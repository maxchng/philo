/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:50:10 by ychng             #+#    #+#             */
/*   Updated: 2024/01/04 20:48:17 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	grab_forks(t_philo_threads *threads)
{
	int	left_fork;
	int	right_fork;

	left_fork = threads->position;
	right_fork = (threads->position + 1) % threads->info->no_of_philos;
	pthread_mutex_lock(&threads->share->forks[left_fork]);
	pthread_mutex_lock(&threads->share->forks[right_fork]);
}
