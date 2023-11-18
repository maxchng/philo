/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:10:59 by ychng             #+#    #+#             */
/*   Updated: 2023/11/18 19:11:37 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	philo_instruction(void *arg)
{
	t_philo_config	*config;

	config = (t_philo_config *)arg;
	//
}

void	exec_threads(t_philo_config config)
{
	pthread_t	*tid;
	size_t		i;

	tid = malloc(sizeof(*tid) * config.number_of_philosophers);
	if (!tid)
	{
		write_error("malloc failed in exec_thread\n");
		exit(-1);
	}
	i = 0;
	while (i < config.number_of_philosophers)
		pthread_create(&tid[i++], NULL, philo_instruction, &config);
}
