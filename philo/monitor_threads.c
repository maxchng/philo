/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:25:23 by ychng             #+#    #+#             */
/*   Updated: 2024/01/14 18:57:57 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static int	check_philo_last_meal_time(t_philo_info	*philos)
{
	struct timeval	start_time;
	size_t			last_meal_time;
	size_t			i;
	size_t			elapsed_time;
	size_t			time_since_last_meal;

	start_time = philos[0].shared_stats->start_time;
	i = 0;
	while (i < philos[0].shared_config->num_of_philos)
	{
		pthread_mutex_lock(&philos[0].shared_stats->last_meal_time_mutex[i]);
		last_meal_time = philos[i].last_meal_time;
		pthread_mutex_unlock(&philos[0].shared_stats->last_meal_time_mutex[i]);
		elapsed_time = get_elapsed_time(start_time);
		time_since_last_meal = (elapsed_time - last_meal_time);
		if (time_since_last_meal > philos[0].shared_config->time_to_die)
		{
			write_activity(&philos[i], "died", start_time);
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	check_exit_condition(t_philo_info *philo)
{
	size_t	num_of_times_to_eat;
	size_t	eating_counter;
	bool	stop_printing;

	num_of_times_to_eat = philo->shared_config->num_of_times_to_eat;
	pthread_mutex_lock(philo->shared_stats->eating_counter_mutex);
	eating_counter = philo->eating_counter;
	pthread_mutex_unlock(philo->shared_stats->eating_counter_mutex);
	pthread_mutex_lock(philo->shared_stats->stop_printing_mutex);
	stop_printing = philo->shared_stats->stop_printing;
	pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
	if (stop_printing)
		return (true);
	return (num_of_times_to_eat != 0 && eating_counter >= num_of_times_to_eat);
}

static bool	check_eating_counter(t_philo_info *philos)
{
	size_t	i;
	size_t	counter;
	size_t	num_of_philos;

	i = 0;
	counter = 0;
	num_of_philos = philos[0].shared_config->num_of_philos;
	while (i < num_of_philos)
	{
		if (check_exit_condition(&philos[i]))
			counter++;
		i++;
	}
	if (counter == num_of_philos)
	{
		pthread_mutex_lock(philos[0].shared_stats->stop_printing_mutex);
		philos[0].shared_stats->stop_printing = true;
		pthread_mutex_unlock(philos[0].shared_stats->stop_printing_mutex);
		return (true);
	}
	return (false);
}

void	monitor_threads(void *arg)
{
	t_philo_info	*philos;

	philos = (t_philo_info *)arg;
	while (1)
	{
		if (check_philo_last_meal_time(philos))
			return ;
		else if (check_eating_counter(philos))
			return ;
		usleep(50);
	}
}
