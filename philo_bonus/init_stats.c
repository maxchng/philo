/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:22:18 by ychng             #+#    #+#             */
/*   Updated: 2024/01/01 15:57:13 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

static void	alloc_forK_sems(t_philo_stats *stats, size_t num_of_philos)
{
	stats->fork_sems = malloc(sizeof(sem_t *) * num_of_philos);
	if (!stats->fork_sems)
	{
		write_error("malloc failed for stats->fork_sems\n");
		exit(-1);
	}
}

static sem_t	*create_semaphores(char *name)
{
	sem_t	*semaphore;

	sem_unlink(name);
	semaphore = sem_open(name, O_CREAT | O_EXCL, 0644, 1);
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

	alloc_forK_sems(stats, num_of_philos);
	i = 0;
	while (i < num_of_philos)
	{
		num = ft_itoa(i);
		name = ft_strjoin("/forks", num, NULL);
		stats->fork_sems[i++] = create_semaphores(name);
		free(num);
		free(name);
	}
	stats->log_sem = create_semaphores("/log");
	stats->stop_printing_sem = create_semaphores("/stop_printing");	
	stats->eating_counter_sem = create_semaphores("/eating_counter");	
}

void	init_stats(t_philo_stats *stats, t_philo_config config)
{
	init_semaphores(stats, config.num_of_philos);
	stats->stop_printing = false;
}
