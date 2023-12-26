/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:41:36 by ychng             #+#    #+#             */
/*   Updated: 2023/12/26 23:07:45 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static void	acquire_fork(t_philo_info *philo, size_t fork_index,
	struct timeval start_time)
{
	size_t	elapsed_time;

	pthread_mutex_lock(&philo->shared_stats->fork_mutexes[fork_index]);
	elapsed_time = get_timestamp_ms(start_time) - philo->last_meal_time;
	if (elapsed_time >= philo->shared_config->time_to_die)
		write_activity(philo, "died", start_time);
	else
		write_activity(philo, "fork", start_time);
}

static void	unlock_forks(t_philo_info *philo, size_t fork1,
	size_t fork2)
{
	pthread_mutex_unlock(&philo->shared_stats->fork_mutexes[fork1]);
	pthread_mutex_unlock(&philo->shared_stats->fork_mutexes[fork2]);
}

static void	acquire_fork_even(t_philo_info *philo, struct timeval start_time)
{
	size_t	pos;
	size_t	num_of_philos;
	size_t	next_fork_index;

	pos = philo->position;
	num_of_philos = philo->shared_config->num_of_philos;
	next_fork_index = (pos + 1) % num_of_philos;
	acquire_fork(philo, pos, start_time);
	acquire_fork(philo, next_fork_index, start_time);
	pthread_mutex_lock(philo->shared_stats->stop_printing_mutex);
	if (philo->shared_stats->stop_printing)
	{
		pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
		unlock_forks(philo, pos, next_fork_index);	
		pthread_exit(0);
	}
	pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
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
	pthread_mutex_lock(philo->shared_stats->stop_printing_mutex);
	if (philo->shared_stats->stop_printing)
	{
		pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
		unlock_forks(philo, next_fork_index, pos);
		pthread_exit(0);
	}
	pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
}

void	acquire_forks(t_philo_info *philo, struct timeval start_time)
{
	if (philo->position % 2 == 0)
		acquire_fork_even(philo, start_time);
	else
		acquire_fork_odd(philo, start_time);
}

void	release_forks(t_philo_info *philo)
{
	size_t	pos;
	size_t	num_of_philos;
	size_t	next_fork_index;

	pos = philo->position;
	num_of_philos = philo->shared_config->num_of_philos;
	next_fork_index = (pos + 1) % num_of_philos;
	if (philo->position % 2 == 0)
		unlock_forks(philo, pos, next_fork_index);
	else
		unlock_forks(philo, next_fork_index, pos);
}

void	handle_eating(t_philo_info *philo, struct timeval start_time)
{
	philo->last_meal_time = get_timestamp_ms(start_time);
	write_activity(philo, "eating", start_time);
	pthread_mutex_lock(philo->shared_stats->eating_counter_mutex);
	philo->eating_counter++;
	pthread_mutex_unlock(philo->shared_stats->eating_counter_mutex);
	usleep(philo->shared_config->time_to_eat * 1000);
}

void	handle_sleeping(t_philo_info *philo, struct timeval start_time)
{
	size_t	current_time;
	size_t	sleep_end_time;
	size_t	sleep_die_time;
	size_t	sleep_duration;

	current_time = get_timestamp_ms(start_time);
	sleep_end_time = current_time + philo->shared_config->time_to_sleep;
	sleep_die_time = current_time + philo->shared_config->time_to_die;
	write_activity(philo, "sleeping", start_time);
	if (sleep_end_time >= sleep_die_time)
	{
		sleep_duration = philo->shared_config->time_to_die;
		usleep(sleep_duration * 1000);
	}
	else
	{
		sleep_duration = philo->shared_config->time_to_sleep;
		usleep(sleep_duration * 1000);
	}
}

void	handle_death(t_philo_info *philo, struct timeval start_time)
{
	size_t	time_to_sleep;
	size_t	time_to_die;

	time_to_sleep = philo->shared_config->time_to_sleep;
	time_to_die = philo->shared_config->time_to_die;
	if (time_to_sleep >= time_to_die)
	{
		write_activity(philo, "died", start_time);
		pthread_exit(0);
	}
}

void	handle_thinking(t_philo_info *philo, struct timeval start_time)
{
	write_activity(philo, "thinking", start_time);
}

void	*philo_lifecycle(void *arg)
{
	t_philo_info	*philo;
	struct timeval	start_time;

	philo = (t_philo_info *)arg;
	start_time = philo->shared_stats->start_time;
	while (1)
	{
		acquire_forks(philo, start_time);
		handle_eating(philo, start_time);
		release_forks(philo);
		handle_sleeping(philo, start_time);
		handle_death(philo, start_time);
		handle_thinking(philo, start_time);
	}
}

void	run_simulation(t_philo_info *philos)
{
	handle_threads(philos, philos->shared_config->num_of_philos);
}
