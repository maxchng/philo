/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:29:32 by ychng             #+#    #+#             */
/*   Updated: 2023/12/26 16:35:36 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static void	create_threads(t_philo_info *philos, size_t num_of_philos,
	pthread_t *tid)
{
	size_t		i;

	i = 0;
	while (i < num_of_philos)
	{
		philos[i].position = i;
		pthread_create(&tid[i], NULL, philo_lifecycle, (void *)(&philos[i]));
		i++;
	}
}

bool	should_exit(t_philo_info *philos, size_t num_of_philos)
{
	size_t	i;
	size_t	eating_counter;
	size_t	num_of_times_to_eat;

	i = 0;
	while (i < num_of_philos)
	{
		num_of_times_to_eat = philos[i].shared_config->num_of_times_to_eat;
		eating_counter = philos[i].eating_counter;
		if (num_of_times_to_eat == 0)
			return (false);
		else if (eating_counter < num_of_times_to_eat)
			return (false);
		else if (philos[0].shared_stats->stop_printing)
			return (false);
		i++;
	}
	return (true);
}

void	handle_threads(t_philo_info *philos, size_t num_of_philos)
{
	pthread_t	*tid;

	tid = malloc(sizeof(*tid) * num_of_philos);
	if (!tid)
	{
		write_error("malloc failed for tid\n");
		free(philos->shared_stats->fork_mutexes);
		exit(-1);
	}
	gettimeofday(&philos[0].shared_stats->start_time, NULL);
	create_threads(philos, num_of_philos, tid);
	while (1)
	{
		if (should_exit(philos, num_of_philos))
		{
			// CLEANUP
			philos[0].shared_stats->stop_printing = true;
			exit(0);
		}
	}
}
