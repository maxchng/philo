/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acquire_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:55:46 by ychng             #+#    #+#             */
/*   Updated: 2024/01/11 21:55:23 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

static void	acquire_fork(t_philo_info *philo, struct timeval start_time)
{
	size_t	elapsed_time;

	sem_wait(philo->shared_stats->fork_sems);
	elapsed_time = get_elapsed_time(start_time) - philo->last_meal_time;
	if (elapsed_time > philo->shared_config->time_to_die)
		write_activity(philo, "died", start_time);
	else
		write_activity(philo, "fork", start_time);
}

void	acquire_forks(t_philo_info *philo, struct timeval start_time)
{
	if (philo->shared_config->num_of_philos == 1)
	{
		write_activity(philo, "died", start_time);
		exit(0);
	}
	acquire_fork(philo, start_time);
	acquire_fork(philo, start_time);
}
