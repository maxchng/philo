/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:29:32 by ychng             #+#    #+#             */
/*   Updated: 2023/11/22 02:51:50 by ychng            ###   ########.fr       */
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

static void monitor_status(t_philo_info *philos, size_t num_of_philos)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if(philos[i++ % num_of_philos].is_dead == true)
		{
			printf("found a dead philo\n");//
			exit(-1);
		}
	}
}

static void	join_threads(size_t num_of_philos, pthread_t *tid)
{
	size_t	i;

	i = 0;
	while (i < num_of_philos)
		pthread_join(tid[i++], NULL);
}

void	handle_threads(t_philo_info *philos, size_t num_of_philos)
{
	pthread_t	*tid;

	tid = malloc(sizeof(*tid) * num_of_philos);
	if (!tid)
	{
		write_error("malloc failed for tid\n");
		free(philos->shared_forks);
		exit(-1);
	}
	create_threads(philos, num_of_philos, tid);
	monitor_status(philos, num_of_philos);
	join_threads(num_of_philos, tid);
}
