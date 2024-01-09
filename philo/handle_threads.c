/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:00:40 by ychng             #+#    #+#             */
/*   Updated: 2024/01/09 12:29:18 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static void	alloc_threads_struct(t_philo_threads **threads, t_philo_info *info,
	t_philo_share *share)
{
	*threads = malloc(sizeof(t_philo_threads) * info->no_of_philos);
	if (!(*threads))
	{
		// FREE SHARE
		free(share->forks);
		printf("malloc failed at *threads\n");
		exit(-1);
	}
}

static void	init_threads_struct(t_philo_threads **threads, t_philo_info *info,
	t_philo_share *share)
{
	int	i;

	i = 0;
	while (i < info->no_of_philos)
	{
		(*threads)[i].info = info;
		(*threads)[i].share = share;
		i++;
	}
}

static void	create_threads(t_philo_threads **threads, pthread_t *tids)
{
	int	i;

	i = 0;
	(*threads)[0].share->start_time = get_time();
	while (i < (*threads)[0].info->no_of_philos)
	{
		(*threads)[i].position = i;
		(*threads)[i].last_ate_time = (*threads)[0].share->start_time;
		pthread_create(&tids[i], NULL, simulation, (void *)&(*threads)[i]);
		i++;
	}
}

static void	monitor_threads(t_philo_threads **threads)
{
	int	i;
	int	time_since_last_meal;

	custom_usleep(threads[0]->info->time_to_eat);
	while (1)
	{
		i = 0;
		while (i < threads[0]->info->no_of_philos)
		{
			printf("%d\n", threads[i]->last_ate_time);
			time_since_last_meal = (get_time() - threads[i]->last_ate_time);
			if (time_since_last_meal > threads[0]->info->time_to_die)
			{
		// 		threads[0]->share->stop_printing = true;
		// 		print_activity("die", threads[i]);
				return ;
			}
			i++;
		}
	}
}

static void	join_threads(pthread_t *tids, int no_of_philos)
{
	int	i;

	i = 0;
	while (i < no_of_philos)
		pthread_join(tids[i], NULL);
}

void	handle_threads(t_philo_threads **threads,
	t_philo_info *info, t_philo_share *share)
{
	pthread_t	*tids;

	alloc_threads_struct(threads, info, share);
	init_threads_struct(threads, info, share);
	tids = malloc(sizeof(pthread_t) * info->no_of_philos);
	if (!tids)
	{
		free(*threads);
		printf("malloc failed at tid\n");
		exit(-1);
	}
	// create_threads(threads, tids);
	monitor_threads(threads);
	join_threads(tids, info->no_of_philos);
	free(tids);
}
