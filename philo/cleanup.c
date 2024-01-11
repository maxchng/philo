/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 03:12:46 by ychng             #+#    #+#             */
/*   Updated: 2024/01/11 18:00:54 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	free_mutexes(t_philo_stats *stats)
{
	free(stats->fork_mutexes);
	free(stats->log_mutex);
	free(stats->stop_printing_mutex);
	free(stats->eating_counter_mutex);
	free(stats->last_meal_time_mutex);
}

void	cleanup(t_philo_info *philos)
{
	size_t	i;

	i = 0;
	while (i < philos->shared_config->num_of_philos)
	{
		pthread_mutex_destroy(&philos[i].shared_stats->fork_mutexes[i]);
		i++;
	}
	pthread_mutex_destroy(philos[0].shared_stats->log_mutex);
	pthread_mutex_destroy(philos[0].shared_stats->stop_printing_mutex);
	pthread_mutex_destroy(philos[0].shared_stats->eating_counter_mutex);
	i = 0;
	while (i < philos->shared_config->num_of_philos)
	{
		pthread_mutex_destroy(&philos[0].shared_stats->last_meal_time_mutex[i]);
		i++;
	}
	free_mutexes(philos->shared_stats);
	free(philos);
}
