/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:08:57 by ychng             #+#    #+#             */
/*   Updated: 2024/01/02 04:08:14 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

static void	destroy_semaphores(t_philo_stats *stats, size_t num_of_philos)
{
	size_t	i;

	i = 0;
	while (i < num_of_philos)
		sem_close(stats->fork_sems[i++]);
	sem_close(stats->log_sem);
	sem_close(stats->eating_counter_sem);
	sem_close(stats->stop_simulation_sem);
	sem_close(stats->start_kill_sem);
}

static void	free_malloc(t_philo_stats *stats)
{
	free(stats->fork_sems);
	free(stats->pids);
}

void	cleanup(t_philo_info *philo, size_t num_of_philos)
{
	destroy_semaphores(philo->shared_stats, num_of_philos);
	free_malloc(philo->shared_stats);
}
