/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lifecycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:17:12 by ychng             #+#    #+#             */
/*   Updated: 2023/12/24 17:34:32 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

size_t	get_timestamp_ms(struct timeval start_time)
{
	struct timeval		current_time;
	size_t				diff_in_ms;

	gettimeofday(&current_time, NULL);
	diff_in_ms = (current_time.tv_sec - start_time.tv_sec) * 1000
		+ (current_time.tv_usec - start_time.tv_usec) / 1000;
	return (diff_in_ms);
}

void	write_activity(t_philo_info *philo, char *activity,
	struct timeval start_time)
{
	pthread_mutex_lock(philo->shared_stats->log_mutexes);
	if (ft_strcmp(activity, "fork") == 0)
	{
		printf("%ld %ld has taken a fork\n",
			get_timestamp_ms(start_time),
			philo->position
			);
	}
	else if (ft_strcmp(activity, "died") == 0)
	{
		printf("%ld %ld died\n",
			get_timestamp_ms(start_time),
			philo->position
			);
	}
	else
	{
		printf("%ld %ld is %s\n",
			get_timestamp_ms(start_time),
			philo->position, activity
			);
	}
	pthread_mutex_unlock(philo->shared_stats->log_mutexes);
}
