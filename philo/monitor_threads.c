/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:25:23 by ychng             #+#    #+#             */
/*   Updated: 2024/01/09 22:17:32 by ychng            ###   ########.fr       */
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

void	monitor_threads(void *arg)
{
	t_philo_info	*philos;
	size_t			i;

	philos = (t_philo_info *)arg;
	while (1)
	{
		i = 0;
		while (i < philos[0].shared_config->num_of_philos)
		{
			if ((get_elapsed_time(philos[0].shared_stats->start_time) - philos[i].last_meal_time) > philos[0].shared_config->time_to_die)
			{
				write_activity(&philos[i], "died", philos[0].shared_stats->start_time);
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
