/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:54:34 by ychng             #+#    #+#             */
/*   Updated: 2024/01/09 04:56:18 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	init_info(t_philo_info *info, char **argv)
{
	validate_input(argv);
	set_info(info, argv);
}

void	init_mutex(t_philo_share *share, t_philo_info *info)
{
	int	i;

	share->forks = malloc(sizeof(pthread_mutex_t) * info->no_of_philos);
	if (!share->forks)
	{
		printf("malloc failed at share->forks\n");
		exit(-1);
	}
	i = 0;
	while (i < info->no_of_philos)
		pthread_mutex_init(&share->forks[i++], NULL);	
}

void	init_share(t_philo_share *share, t_philo_info *info)
{
	share->stop_printing = false;
	init_mutex(share, info);
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
	init_share(&share, &info);
	handle_threads(&threads, &info, &share);
}
