/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:16:31 by ychng             #+#    #+#             */
/*   Updated: 2023/12/26 21:16:19 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static pthread_mutex_t	*create_mutexes(size_t num_of_mutexes)
{
	pthread_mutex_t	*mutexes;
	size_t			i;

	mutexes = malloc(sizeof(*mutexes) * num_of_mutexes);
	if (!mutexes)
	{
		write_error("malloc failed for mutexes");
		return (NULL);
	}
	i = 0;
	while (i < num_of_mutexes)
		pthread_mutex_init(&mutexes[i++], NULL);
	return (mutexes);
}

void	setup_stats(t_philo_stats *stats, t_philo_config config)
{
	stats->fork_mutexes = create_mutexes(config.num_of_philos);
	if (!stats->fork_mutexes)
		exit(-1);
	stats->log_mutexes = create_mutexes(1);
	if (!stats->log_mutexes)
	{
		// NEED TO DESTROY MUTEX
		free(stats->fork_mutexes);
		exit(-1);
	}
	stats->stop_printing_mutex = create_mutexes(1);
	if (!stats->stop_printing_mutex)
	{
		// NEED TO DESTROY MUTEX
		free(stats->fork_mutexes);
		free(stats->log_mutexes);
		exit(-1);
	}
	stats->stop_printing = false;
}
