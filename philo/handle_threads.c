/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:29:32 by ychng             #+#    #+#             */
/*   Updated: 2023/12/26 19:05:35 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

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
		if (philos[0].shared_stats->stop_printing)
			return (true);
		else if (num_of_times_to_eat == 0)
			return (false);
		else if (eating_counter < num_of_times_to_eat)
			return (false);
		i++;
	}
	return (true);
}

void	*check_threads(void *arg)
{
	t_philo_info	*philos;

	philos = (t_philo_info *)arg;
	while (1)
	{
		if (should_exit(philos, philos[0].shared_config->num_of_philos))
		{
			// CLEANUP
			philos[0].shared_stats->stop_printing = true;
			pthread_exit(0);
		}
	}
}

static void	create_threads(t_philo_info *philos, size_t num_of_philos,
	pthread_t *tid)
{
	size_t		i;

	pthread_create(&tid[num_of_philos], NULL, check_threads, (void *)philos);
	i = 0;
	while (i < num_of_philos)
	{
		philos[i].position = i;
		pthread_create(&tid[i], NULL, philo_lifecycle, (void *)(&philos[i]));
		i++;
	}
}

static void	join_threads(pthread_t *tid, size_t num_of_philos)
{
	size_t	i;

	pthread_join(tid[num_of_philos], NULL);
	i = 0;
	while (i < num_of_philos)
		pthread_join(tid[i++], NULL);
}

void	handle_threads(t_philo_info *philos, size_t num_of_philos)
{
	pthread_t	*tid;

	tid = malloc(sizeof(*tid) * (num_of_philos + 1));
	if (!tid)
	{
		write_error("malloc failed for tid\n");
		free(philos->shared_stats->fork_mutexes);
		exit(-1);
	}
	gettimeofday(&philos[0].shared_stats->start_time, NULL);
	create_threads(philos, num_of_philos, tid);
	join_threads(tid, num_of_philos);
}
