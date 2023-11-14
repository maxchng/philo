/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:07:56 by ychng             #+#    #+#             */
/*   Updated: 2023/11/14 17:04:03 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	write_error(const char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
}

int	main(int argc, char **argv)
{
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
	parse_argv(argv);
}
