/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:51:08 by ychng             #+#    #+#             */
/*   Updated: 2024/01/11 18:07:25 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	unlock_forks(t_philo_info *philo, size_t fork1,
	size_t fork2)
{
	pthread_mutex_unlock(&philo->shared_stats->fork_mutexes[fork1]);
	pthread_mutex_unlock(&philo->shared_stats->fork_mutexes[fork2]);
}

void	release_forks(t_philo_info *philo)
{
	size_t	pos;
	size_t	num_of_philos;
	size_t	next_fork_index;

	pos = philo->position;
	num_of_philos = philo->shared_config->num_of_philos;
	next_fork_index = (pos + 1) % num_of_philos;
	unlock_forks(philo, pos, next_fork_index);
}
