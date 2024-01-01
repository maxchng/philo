/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:05:12 by ychng             #+#    #+#             */
/*   Updated: 2024/01/02 01:08:03 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	manage_processes(t_philo_info *philo, size_t num_of_philos)
{
	size_t		i;
	pthread_t	tid;

	i = 0;
	gettimeofday(&philo->shared_stats->start_time, NULL);
	while (i < num_of_philos)
	{
		philo->shared_stats->pids[i] = fork();
		if (philo->shared_stats->pids[i] == 0)
		{
			philo->position = i;
			run_simulation(philo);
		}
		else if (philo->shared_stats->pids[i] < 0)
		{
			cleanup(philo, num_of_philos);
			write_error("fork failed for pid\n");
			exit(-1);
		}
		i++;
	}
	pthread_create(&tid, NULL, start_kill, (void *)philo);
	pthread_join(tid, NULL);
	while (i--)
		waitpid(-1, NULL, 0);
}
