/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:51:08 by ychng             #+#    #+#             */
/*   Updated: 2024/01/03 22:58:05 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	release_forks(t_philo_info *philo)
{
	size_t	left_fork;
	size_t	right_fork;

	left_fork = philo->position;
	right_fork = (philo->position + 1) % philo->shared_config->num_of_philos;
	pthread_mutex_unlock(&philo->shared_stats->fork_mutexes[left_fork]);
	pthread_mutex_unlock(&philo->shared_stats->fork_mutexes[right_fork]);
}
