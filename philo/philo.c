/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:07:56 by ychng             #+#    #+#             */
/*   Updated: 2023/11/18 22:03:37 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	write_error(const char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
}

void	init_dining_philo(t_dining_philo *dp)
{
	dp->chopsticks = NULL;
	dp->philosophers = NULL;
	dp->config = (t_philo_config){0};
}

int	main(int argc, char **argv)
{
	t_dining_philo	dp;

	if (argc != 5 && argc != 6)
	{
		write_error("Usage: ./pipex <arg1> <arg2> <arg3> <arg4> [<arg5>]\n");
		write_error("<arg1>: number_of_philosophers\n");
		write_error("<arg2>: time to die\n");
		write_error("<arg3>: time to eat\n");
		write_error("<arg4>: time to sleep\n");
		write_error("[<arg5>]: number_of_times_each_philosopher_must_eat\n");
		exit(EXIT_FAILURE);
	}
	init_dining_philo(&dp);
	parse_argv(&dp.config, argv);
	exec_threads(&dp);
}
