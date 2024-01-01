/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:58:08 by ychng             #+#    #+#             */
/*   Updated: 2024/01/01 17:12:30 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	unlock_forks(t_philo_info *philo, size_t fork1,
	size_t fork2)
{
	sem_post(philo->shared_stats->fork_sems[fork1]);
	sem_post(philo->shared_stats->fork_sems[fork2]);
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
