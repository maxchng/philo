/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:10:59 by ychng             #+#    #+#             */
/*   Updated: 2023/11/18 22:42:33 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	*philo_instructions(void *arg)
{
	t_dining_philo	*dp;

	dp = (t_dining_philo *)arg;
	//
	pthread_exit(0);
}

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

void	exec_threads(t_dining_philo *dp)
{
	pthread_t	*tid;
	size_t		philo_count;

	alloc_space_for_philo_n_chopsticks(dp);
	philo_count = dp->config.number_of_philosophers;
	tid = malloc(sizeof(*tid) * philo_count);
	if (!tid)
	{
		write_error("malloc failed for tid in exec_threads\n");
		free(dp->philosophers);
		free(dp->chopsticks);
		exit(-1);
	}
	while (philo_count--)
		pthread_create(tid++, NULL, philo_instructions, dp);
}
