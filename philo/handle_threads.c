/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:00:40 by ychng             #+#    #+#             */
/*   Updated: 2024/01/04 17:36:26 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static void	alloc_tids(t_philo_main *main)
{
	main->share->tids = malloc(sizeof(pthread_t) * main->info->no_of_philos);
	if (!main->share->tids)
	{
		// FIRST SHARE
		printf("malloc failed at tid\n");
		exit(-1);
	}
}

static void	alloc_threads(t_philo_main *main)
{
	main->threads = malloc(sizeof(t_philo_threads) * main->info->no_of_philos);
	if (!main->threads)
	{
		// FREE SHARE
		free(main->share->tids);
		printf("malloc failed at main->threads\n");
		exit(-1);
	}
}

static void	create_threads(t_philo_main *main)
{
	int	i;

	i = 0;
	while (i < main->info->no_of_philos)
	{
		main->threads[i].position = i;
		pthread_create(&main->share->tids[i++], NULL, simulation, (void *)main);
	}
}

static void	join_threads(t_philo_main *main)
{
	int	i;

	i = 0;
	while (i < main->info->no_of_philos)
		pthread_join(main->share->tids[i++], NULL);
}

void	handle_threads(t_philo_main *main)
{
	alloc_tids(main);
	alloc_threads(main);
	create_threads(main);
	join_threads(main);
}
