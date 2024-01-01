/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_eat_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 02:51:25 by ychng             #+#    #+#             */
/*   Updated: 2024/01/02 03:57:06 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	*monitor_eat_count(void *arg)
{
	t_philo_info	*philo;
	size_t			i;

	philo = (t_philo_info *)arg;
	i = 0;
	while (i++ < philo->shared_config->num_of_philos)
		sem_wait(philo->shared_stats->eating_counter_sem);
	sem_post(philo->shared_stats->start_kill_sem);
	pthread_exit(0);
}
