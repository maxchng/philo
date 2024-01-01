/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acquire_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:55:46 by ychng             #+#    #+#             */
/*   Updated: 2024/01/02 00:18:32 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

static void	acquire_fork(t_philo_info *philo, size_t fork_index,
	struct timeval start_time)
{
	size_t	elapsed_time;

	sem_wait(philo->shared_stats->fork_sems[fork_index]);
	elapsed_time = get_elapsed_time(start_time) - philo->last_meal_time;
	if (elapsed_time > philo->shared_config->time_to_die)
		write_activity(philo, "died", start_time);
	else
		write_activity(philo, "fork", start_time);
}

static void	acquire_fork_even(t_philo_info *philo, struct timeval start_time)
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
		exit(0);
	}
	acquire_fork(philo, pos, start_time);
	acquire_fork(philo, next_fork_index, start_time);
	sem_wait(philo->shared_stats->stop_printing_sem);
	if (philo->shared_stats->stop_printing)
	{
		sem_post(philo->shared_stats->stop_printing_sem);
		unlock_forks(philo, pos, next_fork_index);
		exit(0);
	}
	sem_post(philo->shared_stats->stop_printing_sem);
}

static void	acquire_fork_odd(t_philo_info *philo, struct timeval start_time)
{
	size_t	pos;
	size_t	num_of_philos;
	size_t	next_fork_index;

	pos = philo->position;
	num_of_philos = philo->shared_config->num_of_philos;
	next_fork_index = (pos + 1) % num_of_philos;
	acquire_fork(philo, next_fork_index, start_time);
	acquire_fork(philo, pos, start_time);
	sem_wait(philo->shared_stats->stop_printing_sem);
	if (philo->shared_stats->stop_printing)
	{
		sem_post(philo->shared_stats->stop_printing_sem);
		unlock_forks(philo, next_fork_index, pos);
		exit(0);
	}
	sem_post(philo->shared_stats->stop_printing_sem);
}

void	acquire_forks(t_philo_info *philo, struct timeval start_time)
{
	if (philo->position % 2 == 0)
		acquire_fork_even(philo, start_time);
	else
		acquire_fork_odd(philo, start_time);
}
