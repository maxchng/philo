/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:07:56 by ychng             #+#    #+#             */
/*   Updated: 2023/12/24 17:52:23 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	write_error(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
}

int	main(int argc, char **argv)
{
	t_philo_config	config;
	t_philo_stats	stats;
	t_philo_info	*philos;

	if (argc != 5 && argc != 6)
	{
		write_error("Usage: ./pipex <arg1> <arg2> <arg3> <arg4> [<arg5>]\n");
		write_error("<arg1>: number of philosophers\n");
		write_error("<arg2>: time to die\n");
		write_error("<arg3>: time to eat\n");
		write_error("<arg4>: time to sleep\n");
		write_error("[<arg5>]: number of times each philosopher must eat\n");
		exit(EXIT_FAILURE);
	}
	parse_argv(&config, argv);
	setup_stats(&stats, config);
	create_philos(&philos, &config, &stats);
	run_simulation(philos);
}
