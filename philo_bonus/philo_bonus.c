/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:19:02 by ychng             #+#    #+#             */
/*   Updated: 2024/01/01 17:35:50 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	write_error(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
}

int	main(int argc, char **argv)
{
	t_philo_config	config;
	t_philo_stats	stats;
	t_philo_info	philo;

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
	init_stats(&stats, config);
	init_philo(&philo, &config, &stats);
	create_processes(&philo, config.num_of_philos);
	cleanup(&philo, config.num_of_philos);
}
