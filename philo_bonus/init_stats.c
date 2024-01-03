/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:22:18 by ychng             #+#    #+#             */
/*   Updated: 2024/01/03 16:58:32 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

static void	alloc_pids(t_philo_stats *stats, size_t num_of_philos)
{
	stats->pids = malloc(sizeof(pid_t) * num_of_philos);
	if (!stats->pids)
	{
		write_error("malloc failed for stats->pid\n");
		exit(-1);
	}
}

static void	alloc_fork_sems(t_philo_stats *stats, size_t num_of_philos)
{
	stats->fork_sems = malloc(sizeof(sem_t *) * num_of_philos);
	if (!stats->fork_sems)
	{
		free(stats->pids);
		write_error("malloc failed for stats->fork_sems\n");
		exit(-1);
	}
}

static sem_t	*create_semaphores(char *name, size_t initial_val)
{
	sem_t	*semaphore;

	sem_unlink(name);
	semaphore = sem_open(name, O_CREAT | O_EXCL, 0644, initial_val);
	if (semaphore == SEM_FAILED)
	{
		write_error("sem_open failed for semaphore\n");
		exit(-1);
	}
	return (semaphore);
}

static void	init_semaphores(t_philo_stats *stats, size_t num_of_philos)
{
	size_t	i;
	char	*num;
	char	*name;

	alloc_fork_sems(stats, num_of_philos);
	i = 0;
	while (i < num_of_philos)
	{
		num = ft_itoa(i);
		name = ft_strjoin("/forks", num, NULL);
		stats->fork_sems[i++] = create_semaphores(name, 1);
		free(num);
		free(name);
	}
	stats->log_sem = create_semaphores("/log", 1);
	stats->eating_counter_sem = create_semaphores("/eating_counter", 0);
	stats->stop_simulation_sem = create_semaphores("/stop_simulation_sem", 1);
	stats->start_kill_sem = create_semaphores("/start_kill_sem", 0);
}

void	init_stats(t_philo_stats *stats, t_philo_config config)
{
	alloc_pids(stats, config.num_of_philos);
	init_semaphores(stats, config.num_of_philos);
}
