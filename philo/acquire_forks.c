/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acquire_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:50:02 by ychng             #+#    #+#             */
/*   Updated: 2024/01/03 23:41:13 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

// static void	acquire_fork(t_philo_info *philo, size_t fork_index,
// 	struct timeval start_time)
// {
// 	size_t	elapsed_time;

// 	pthread_mutex_lock(&philo->shared_stats->fork_mutexes[fork_index]);
// 	elapsed_time = get_elapsed_time(start_time) - philo->last_meal_time;
// 	if (elapsed_time > philo->shared_config->time_to_die)
// 		log_activity(philo, "died", start_time);
// 	else
// 		log_activity(philo, "fork", start_time);
// }

// static void	acquire_fork_even(t_philo_info *philo, struct timeval start_time)
// {
// 	size_t	pos;
// 	size_t	num_of_philos;
// 	size_t	next_fork_index;

// 	pos = philo->position;
// 	num_of_philos = philo->shared_config->num_of_philos;
// 	next_fork_index = (pos + 1) % num_of_philos;
// 	if (num_of_philos == 1)
// 	{
// 		log_activity(philo, "died", start_time);
// 		pthread_exit(0);
// 	}
// 	acquire_fork(philo, pos, start_time);
// 	acquire_fork(philo, next_fork_index, start_time);
// 	pthread_mutex_lock(philo->shared_stats->stop_printing_mutex);
// 	if (philo->shared_stats->stop_printing)
// 	{
// 		pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
// 		unlock_forks(philo, pos, next_fork_index);
// 		pthread_exit(0);
// 	}
// 	pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
// }

// static void	acquire_fork_odd(t_philo_info *philo, struct timeval start_time)
// {
// 	size_t	pos;
// 	size_t	num_of_philos;
// 	size_t	next_fork_index;

// 	pos = philo->position;
// 	num_of_philos = philo->shared_config->num_of_philos;
// 	next_fork_index = (pos + 1) % num_of_philos;
// 	acquire_fork(philo, next_fork_index, start_time);
// 	acquire_fork(philo, pos, start_time);
// 	pthread_mutex_lock(philo->shared_stats->stop_printing_mutex);
// 	if (philo->shared_stats->stop_printing)
// 	{
// 		pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
// 		unlock_forks(philo, next_fork_index, pos);
// 		pthread_exit(0);
// 	}
// 	pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
// }

// void	acquire_forks(t_philo_info *philo, struct timeval start_time)
// {
// 	if (philo->position % 2 == 0)
// 		acquire_fork_even(philo, start_time);
// 	else
// 		acquire_fork_odd(philo, start_time);
// }

static void	acquire_left_fork(t_philo_info *philo, struct timeval start_time)
{
	size_t	left_fork;
	bool	stop_print;

	left_fork = philo->position;
	pthread_mutex_lock(&philo->shared_stats->fork_mutexes[left_fork]);
	pthread_mutex_lock(philo->shared_stats->stop_printing_mutex);
	stop_print = philo->shared_stats->stop_printing;
	pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
	if (philo->shared_stats->stop_printing)
	{
		log_activity(philo, "died", start_time);
		pthread_mutex_unlock(&philo->shared_stats->fork_mutexes[left_fork]);
		pthread_exit(0);
	}
	log_activity(philo, "fork", start_time);
}

static void	acquire_right_fork(t_philo_info *philo, struct timeval start_time)
{
	size_t	left_fork;
	size_t	right_fork;
	bool	stop_print;

	left_fork = philo->position;
	right_fork = (philo->position + 1) % philo->shared_config->num_of_philos;
	pthread_mutex_lock(&philo->shared_stats->fork_mutexes[right_fork]);
	pthread_mutex_lock(philo->shared_stats->stop_printing_mutex);
	stop_print = philo->shared_stats->stop_printing;
	pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
	if (stop_print)
	{
		log_activity(philo, "died", start_time);
		release_forks(philo);
		pthread_exit(0);
	}
	log_activity(philo, "fork", start_time);
}

void	acquire_forks(t_philo_info *philo, struct timeval start_time)
{
	acquire_left_fork(philo, start_time);
	acquire_right_fork(philo, start_time);
}
