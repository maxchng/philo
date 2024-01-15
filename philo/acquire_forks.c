/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acquire_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:50:02 by ychng             #+#    #+#             */
/*   Updated: 2024/01/15 21:56:14 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static void	acquire_fork(t_philo_info *philo, size_t fork_index)
{
	pthread_mutex_lock(&philo->shared_stats->fork_mutexes[fork_index]);
	write_activity(philo, "fork", philo->shared_stats->start_time);
}

void	acquire_forks(t_philo_info *philo, struct timeval start_time)
{
	size_t	pos;
	size_t	num_of_philos;
	size_t	next_fork_index;

	pos = philo->position;
	num_of_philos = philo->shared_config->num_of_philos;
	next_fork_index = (pos + 1) % num_of_philos;
	if (num_of_philos == 1)
	{
		write_activity(philo, "died", start_time);
		pthread_exit(0);
	}
	acquire_fork(philo, pos);
	acquire_fork(philo, next_fork_index);
	pthread_mutex_lock(philo->shared_stats->stop_printing_mutex);
	if (philo->shared_stats->stop_printing)
	{
		pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
		unlock_forks(philo, pos, next_fork_index);
		pthread_exit(0);
	}
	pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
}
