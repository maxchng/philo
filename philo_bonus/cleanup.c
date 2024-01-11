/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:08:57 by ychng             #+#    #+#             */
/*   Updated: 2024/01/11 21:55:40 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

static void	destroy_semaphores(t_philo_stats *stats)
{
	sem_close(stats->fork_sems);
	sem_close(stats->log_sem);
	sem_close(stats->eating_counter_sem);
	sem_close(stats->stop_simulation_sem);
	sem_close(stats->start_kill_sem);
}

static void	free_malloc(t_philo_stats *stats)
{
	free(stats->pids);
}

void	cleanup(t_philo_info *philo)
{
	destroy_semaphores(philo->shared_stats);
	free_malloc(philo->shared_stats);
}
