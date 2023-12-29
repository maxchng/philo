/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:51:08 by ychng             #+#    #+#             */
/*   Updated: 2023/12/29 16:20:16 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

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
	if (philo->position % 2 == 0)
		unlock_forks(philo, pos, next_fork_index);
	else
		unlock_forks(philo, next_fork_index, pos);
}
