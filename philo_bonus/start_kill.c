/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_kill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:49:16 by ychng             #+#    #+#             */
/*   Updated: 2024/01/02 03:57:15 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

// static bool	check_exit_condition(t_philo_info *philo)
// {
// 	size_t	num_of_times_to_eat;
// 	size_t	eating_counter;
// 	bool	stop_printing;

// 	num_of_times_to_eat = philo->shared_config->num_of_times_to_eat;
// 	sem_wait(philo->shared_stats->eating_counter_sem);
// 	eating_counter = philo->eating_counter;
// 	sem_post(philo->shared_stats->eating_counter_sem);
// 	sem_wait(philo->shared_stats->stop_printing_sem);
// 	stop_printing = philo->shared_stats->stop_printing;
// 	sem_post(philo->shared_stats->stop_printing_sem);
// 	if (stop_printing)
// 		return (true);
// 	return (num_of_times_to_eat != 0 && eating_counter >= num_of_times_to_eat);
// }

void	*start_kill(void *arg)
{
	t_philo_info	*philo;
	size_t			i;

	philo = (t_philo_info *)arg;
	i = 0;
	sem_wait(philo->shared_stats->start_kill_sem);
	while (i < philo->shared_config->num_of_philos)
	{
		kill(philo->shared_stats->pids[i], SIGTERM);
		i++;
	}
	sem_post(philo->shared_stats->start_kill_sem);
	pthread_exit(0);
}
