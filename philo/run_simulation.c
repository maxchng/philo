/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:41:36 by ychng             #+#    #+#             */
/*   Updated: 2023/11/22 02:50:01 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

// void	acquire_forks(t_philo_info *philo, struct timeval start_time)
// {
// 	size_t	pos;
// 	size_t	num_of_philos;

// 	pos = philo->position;
// 	num_of_philos = philo->shared_config->num_of_philos;
// 	if (philo->position % 2 == 0)
// 	{
// 		pthread_mutex_lock(&philo->shared_forks[pos]);
// 		write_activity(philo, "fork", start_time);
// 		pthread_mutex_lock(&philo->shared_forks[(pos + 1) % num_of_philos]);
// 		write_activity(philo, "fork", start_time);
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(&philo->shared_forks[(pos + 1) % num_of_philos]);
// 		write_activity(philo, "fork", start_time);
// 		pthread_mutex_lock(&philo->shared_forks[pos]);
// 		write_activity(philo, "fork", start_time);
// 	}
// }

// void	release_forks(t_philo_info *philo)
// {
// 	size_t	pos;
// 	size_t	num_of_philos;

// 	pos = philo->position;
// 	num_of_philos = philo->shared_config->num_of_philos;
// 	if (philo->position % 2 == 0)
// 	{
// 		pthread_mutex_unlock(&philo->shared_forks[pos]);
// 		pthread_mutex_unlock(&philo->shared_forks[(pos + 1) % num_of_philos]);
// 	}
// 	else
// 	{
// 		pthread_mutex_unlock(&philo->shared_forks[(pos + 1) % num_of_philos]);
// 		pthread_mutex_unlock(&philo->shared_forks[pos]);
// 	}
// }

// void	handle_eating(t_philo_info *philo, struct timeval start_time)
// {
// 	philo->last_meal_time = get_timestamp_ms(start_time);
// 	write_activity(philo, "eating", start_time);
// 	usleep(philo->shared_config->time_to_eat * 1000);
// }

// void	handle_sleeping(t_philo_info *philo, struct timeval start_time)
// {
// 	size_t	current_time;
// 	size_t	sleep_end_time;
// 	size_t	sleep_die_time;
// 	size_t	sleep_duration;

// 	current_time = get_timestamp_ms(start_time);
// 	sleep_end_time = current_time + philo->shared_config->time_to_sleep;
// 	sleep_die_time = current_time + philo->shared_config->time_to_die;
// 	write_activity(philo, "sleeping", start_time);
// 	if (sleep_end_time >= sleep_die_time)
// 	{
// 		sleep_duration = sleep_end_time - sleep_die_time;
// 		usleep(sleep_duration * 1000);
// 	}
// 	else
// 		usleep(philo->shared_config->time_to_sleep * 1000);
// }

// void	handle_death(t_philo_info *philo, struct timeval start_time)
// {
// 	size_t				current_time;
// 	size_t				time_since_last_meal;

// 	current_time = get_timestamp_ms(start_time);
// 	time_since_last_meal = current_time - philo->last_meal_time;
// 	if (time_since_last_meal >= (philo->shared_config->time_to_die))
// 	{
// 		write_activity(philo, "died", start_time);
// 		exit(-1);
// 	}
// }

// void	*philo_lifecycle(void *arg)
// {
// 	t_philo_info	*philo;
// 	struct timeval	start_time;

// 	philo = (t_philo_info *)arg;
// 	gettimeofday(&start_time, NULL);
// 	handle_death(philo, start_time);
// 	acquire_forks(philo, start_time);
// 	handle_eating(philo, start_time);
// 	release_forks(philo);
// 	handle_sleeping(philo, start_time);
// 	handle_death(philo, start_time);
// 	pthread_exit(0);
// }

void	run_simulation(t_philo_info *philos)
{
	handle_threads(philos, philos->shared_config->num_of_philos);
}
