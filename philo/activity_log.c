/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity_log.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:17:12 by ychng             #+#    #+#             */
/*   Updated: 2023/12/29 07:02:27 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

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
		philo->shared_stats->stop_printing = true;
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
	pthread_mutex_lock(philo->shared_stats->log_mutex);
	pthread_mutex_lock(philo->shared_stats->stop_printing_mutex);
	if (!philo->shared_stats->stop_printing)
		print_activity(philo, activity, start_time);
	pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
	pthread_mutex_unlock(philo->shared_stats->log_mutex);
}
