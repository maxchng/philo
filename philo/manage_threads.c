/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:21:26 by ychng             #+#    #+#             */
/*   Updated: 2024/01/02 13:11:49 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static void	create_threads(t_philo_info *philos, size_t num_of_philos,
	pthread_t *tid)
{
	size_t		i;

	pthread_create(&tid[num_of_philos], NULL, monitor_threads, (void *)philos);
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

void	manage_threads(t_philo_info *philos, size_t num_of_philos)
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
	free(tid);
}
