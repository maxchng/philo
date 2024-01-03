/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:25:23 by ychng             #+#    #+#             */
/*   Updated: 2024/01/03 23:44:24 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

// static bool	check_exit_condition(t_philo_info *philo)
// {
// 	size_t	num_of_times_to_eat;
// 	size_t	eating_counter;
// 	bool	stop_printing;

// 	num_of_times_to_eat = philo->shared_config->num_of_times_to_eat;
// 	pthread_mutex_lock(philo->shared_stats->eating_counter_mutex);
// 	eating_counter = philo->eating_counter;
// 	pthread_mutex_unlock(philo->shared_stats->eating_counter_mutex);
// 	pthread_mutex_lock(philo->shared_stats->stop_printing_mutex);
// 	stop_printing = philo->shared_stats->stop_printing;
// 	pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
// 	if (stop_printing)
// 		return (true);
// 	return (num_of_times_to_eat != 0 && eating_counter >= num_of_times_to_eat);
// }

// static bool	should_exit(t_philo_info *philos, size_t num_of_philos)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < num_of_philos)
// 	{
// 		if (check_exit_condition(&philos[i]))
// 			return (true);
// 		i++;
// 	}
// 	return (false);
// }

// void	*monitor_threads(void *arg)
// {
// 	t_philo_info	*philos;

// 	philos = (t_philo_info *)arg;
// 	while (1)
// 	{
// 		if (should_exit(philos, philos[0].shared_config->num_of_philos))
// 		{
// 			pthread_mutex_lock(philos[0].shared_stats->stop_printing_mutex);
// 			philos[0].shared_stats->stop_printing = true;
// 			pthread_mutex_unlock(philos[0].shared_stats->stop_printing_mutex);
// 			pthread_exit(0);
// 		}
// 	}
// }

static size_t	calc_time_since_last_meal(t_philo_info *philos, size_t i)
{
	size_t	philo_last_meal_time;
	size_t	current_time;

	philo_last_meal_time = philos[i].last_meal_time;
	current_time = get_elapsed_time(philos[0].shared_stats->start_time);
	return (current_time - philo_last_meal_time);
}

void	monitor_threads(t_philo_info *philos, size_t num_of_philos)
{
	size_t	i;
	size_t	time_since_last_meal;

	custom_usleep(philos[0].shared_config->time_to_eat);
	while (1)
	{
		i = 0;
		while (i < num_of_philos)
		{
			time_since_last_meal = calc_time_since_last_meal(philos, i);
			if (time_since_last_meal > philos[0].shared_config->time_to_die)
			{
				printf("philo: %ld, time_since_last_meal: %ld\n", i, time_since_last_meal);
				pthread_mutex_lock(philos[0].shared_stats->stop_printing_mutex);
				philos[0].shared_stats->stop_printing = true;
				pthread_mutex_unlock(philos[0].shared_stats->stop_printing_mutex);
				return ;
			}
			i++;
		}
		usleep(50);
	}
}
