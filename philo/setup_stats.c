/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:16:31 by ychng             #+#    #+#             */
/*   Updated: 2023/12/29 03:13:51 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static pthread_mutex_t	*create_mutexes(size_t num)
{
	pthread_mutex_t	*mutexes;
	size_t			i;

	mutexes = malloc(sizeof(*mutexes) * num);
	if (!mutexes)
	{
		write_error("malloc failed for mutexes");
		return (NULL);
	}
	i = 0;
	while (i < num)
		pthread_mutex_init(&mutexes[i++], NULL);
	return (mutexes);
}

static bool	init_mutex(pthread_mutex_t **mutex, size_t num)
{
	*mutex = create_mutexes(num);
	return (*mutex != NULL);
}

void	setup_stats(t_philo_stats *stats, t_philo_config config)
{
	if (!init_mutex(&stats->fork_mutexes, config.num_of_philos)
		|| !init_mutex(&stats->log_mutex, 1)
		|| !init_mutex(&stats->stop_printing_mutex, 1)
		|| !init_mutex(&stats->eating_counter_mutex, 1))
	{
		free_mutexes(stats);
		exit(-1);
	}
	stats->stop_printing = false;
}
