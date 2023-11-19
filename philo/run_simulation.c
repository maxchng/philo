/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:41:36 by ychng             #+#    #+#             */
/*   Updated: 2023/11/20 00:31:44 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	*philo_lifecycle(void *arg)
{
	t_philo_info	*philo;

	philo = (t_philo_info *)arg;
	//
	pthread_exit(0);
}

void	run_simulation(t_philo_info *philos)
{
	handle_threads(philos, philos->shared_config->num_of_philos);
}
