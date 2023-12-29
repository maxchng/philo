/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:01:05 by ychng             #+#    #+#             */
/*   Updated: 2023/12/29 16:19:51 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

static void	free_stats(t_philo_stats *stats)
{
	free(stats->fork_mutexes);
	free(stats->log_mutex);
}

static void	init_philo(t_philo_info *philo, t_philo_config *config,
	t_philo_stats *stats)
{
	*philo = (t_philo_info){0};
	philo->shared_config = config;
	philo->shared_stats = stats;
}

void	create_philos(t_philo_info **philos, t_philo_config *config,
	t_philo_stats *stats)
{
	size_t	i;

	*philos = malloc(sizeof(**philos) * config->num_of_philos);
	if (!(*philos))
	{
		write_error("malloc failed for *philos\n");
		free_stats(stats);
		exit(-1);
	}
	i = 0;
	while (i < config->num_of_philos)
		init_philo(&(*philos)[i++], config, stats);
}
