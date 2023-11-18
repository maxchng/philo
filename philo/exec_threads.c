/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:10:59 by ychng             #+#    #+#             */
/*   Updated: 2023/11/18 23:06:24 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static void	alloc_space_for_philo_n_chopsticks(t_dining_philo *dp)
{
	size_t	philo_count;

	philo_count = dp->config.number_of_philosophers;
	dp->philosophers = malloc(sizeof(*dp->philosophers) * philo_count);
	if (!dp->philosophers)
	{
		write_error("malloc failed for philosophers in alloc_space\n");
		exit(-1);
	}
	dp->chopsticks = malloc(sizeof(*dp->chopsticks) * philo_count);
	if (!dp->chopsticks)
	{
		write_error("malloc failed for chopsticks in alloc_space\n");
		exit(-1);
	}
}

void	*philo_instructions(void *arg)
{
	t_dining_philo	*dp;

	dp = (t_dining_philo *)arg;
	printf("hello there\n");
	pthread_exit(0);
}

void	create_threads(t_dining_philo *dp, pthread_t *tid)
{
	size_t	i;

	i = 0;
	while (i < dp->config.number_of_philosophers)
		pthread_create(&tid[i++], NULL, philo_instructions, dp);
}

void	join_threads(t_dining_philo *dp, pthread_t *tid)
{
	size_t	i;

	i = 0;
	while (i < dp->config.number_of_philosophers)
		pthread_join(tid[i++], NULL);
}

void	exec_threads(t_dining_philo *dp)
{
	pthread_t	*tid;

	alloc_space_for_philo_n_chopsticks(dp);
	tid = malloc(sizeof(*tid) * dp->config.number_of_philosophers);
	if (!tid)
	{
		write_error("malloc failed for tid in exec_threads\n");
		free(dp->philosophers);
		free(dp->chopsticks);
		exit(-1);
	}
	create_threads(dp, tid);
	join_threads(dp, tid);
	printf("main\n");
}
