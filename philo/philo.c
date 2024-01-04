/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:54:34 by ychng             #+#    #+#             */
/*   Updated: 2024/01/04 19:39:49 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	init_info(t_philo_info *info, char **argv)
{
	validate_input(argv);
	set_info(info, argv);
}

int	main(int argc, char **argv)
{
	t_philo_info	info;
	t_philo_share	share;
	t_philo_threads	*threads;

	if (argc != 5 && argc != 6)
	{
		printf(
			"Usage: ./pipex <arg1> <arg2> <arg3> <arg4> [<arg5>]\n"
			"<arg1>: number of philosophers\n"
			"<arg2>: time to die\n"
			"<arg3>: time to eat\n"
			"<arg4>: time to sleep\n"
			"[<arg5>]: number of times each philosopher must eat\n"
			);
		exit(-1);
	}
	init_info(&info, argv);
	handle_threads(&threads, &info, &share);
}
