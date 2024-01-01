/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:05:12 by ychng             #+#    #+#             */
/*   Updated: 2024/01/01 17:20:17 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	create_processes(t_philo_info philo, size_t num_of_philos)
{
	size_t		i;
	pthread_t	tid;
	pid_t		pid;

	i = 0;
	gettimeofday(&philo.shared_stats->start_time, NULL);
	pthread_create(&tid, NULL, monitor_simulation, (void *)(&philo));
	while (i < num_of_philos)
	{
		pid = fork();
		if (pid == 0)
		{
			philo.position = i;
			run_simulation(philo);
		}
		else if (pid < 0)
		{
			cleanup(philo, num_of_philos);
			write_error("fork failed for pid\n");
			exit(-1);
		}
		i++;
	}
	pthread_join(tid, NULL);
	while (i--)
		waitpid(-1, NULL, 0);
}
