/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:05:12 by ychng             #+#    #+#             */
/*   Updated: 2024/01/02 03:57:34 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	manage_processes(t_philo_info *philo, size_t num_of_philos)
{
	size_t		i;
	pthread_t	eat;
	pthread_t	kill;

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
	if (philo->shared_config->num_of_times_to_eat != 0)
	{
		pthread_create(&eat, NULL, monitor_eat_count, (void *)philo);
		pthread_detach(eat);
	}
	pthread_create(&kill, NULL, start_kill, (void *)philo);
	pthread_detach(kill);
	while (i--)
		waitpid(-1, NULL, 0);
}
