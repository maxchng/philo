/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:30:26 by ychng             #+#    #+#             */
/*   Updated: 2024/01/09 05:02:09 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	*simulation(void *arg)
{
	t_philo_threads	*threads;

	threads = (t_philo_threads *)arg;
	while (1)
	{
		grab_forks(threads);
		release_forks(threads);
	}
	pthread_exit(0);
}
