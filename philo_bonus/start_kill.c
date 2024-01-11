/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_kill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:49:16 by ychng             #+#    #+#             */
/*   Updated: 2024/01/11 22:36:31 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	*start_kill(void *arg)
{
	t_philo_info	*philo;
	size_t			i;

	philo = (t_philo_info *)arg;
	i = 0;
	sem_wait(philo->shared_stats->start_kill_sem);
	while (i < philo->shared_config->num_of_philos)
	{
		if (philo->shared_config->num_of_times_to_eat != 0)
			sem_post(philo->shared_stats->eating_counter_sem);
		kill(philo->shared_stats->pids[i], SIGTERM);
		i++;
	}
	sem_post(philo->shared_stats->start_kill_sem);
	pthread_exit(0);
}
