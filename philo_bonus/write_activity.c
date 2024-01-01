/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_activity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:01:17 by ychng             #+#    #+#             */
/*   Updated: 2024/01/02 04:07:28 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

static void	print_activity(t_philo_info *philo, char *activity,
	struct timeval start_time)
{
	if (ft_strcmp(activity, "fork") == 0)
	{
		printf("%ld %ld has taken a fork\n",
			get_elapsed_time(start_time),
			philo->position
			);
	}
	else if (ft_strcmp(activity, "died") == 0)
	{
		printf("%ld %ld died\n",
			get_elapsed_time(start_time),
			philo->position
			);
		sem_post(philo->shared_stats->start_kill_sem);
		sem_wait(philo->shared_stats->stop_simulation_sem);
	}
	else
	{
		printf("%ld %ld is %s\n",
			get_elapsed_time(start_time),
			philo->position, activity
			);
	}
}

void	write_activity(t_philo_info *philo, char *activity,
	struct timeval start_time)
{
	sem_wait(philo->shared_stats->log_sem);
	sem_wait(philo->shared_stats->stop_simulation_sem);
	print_activity(philo, activity, start_time);
	sem_post(philo->shared_stats->stop_simulation_sem);
	sem_post(philo->shared_stats->log_sem);
}
