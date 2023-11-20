/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lifecycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:17:12 by ychng             #+#    #+#             */
/*   Updated: 2023/11/20 22:54:39 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

unsigned long long	get_timestamp(struct timeval start_time)
{
	struct timeval		current_time;
	unsigned long long	diff_in_ms;

	gettimeofday(&current_time, NULL);
	diff_in_ms = (current_time.tv_sec - start_time.tv_sec) * 1000ULL
		+ (current_time.tv_usec - start_time.tv_usec) / 1000ULL;
	return (diff_in_ms);
}

void	write_activity(t_philo_info *philo, char *activity,
	struct timeval start_time)
{
	if (ft_strcmp(activity, "fork") == 0)
	{
		printf(
			"%llums %ld has taken a fork\n",
			get_timestamp(start_time),
			philo->position
			);
	}
	else if (ft_strcmp(activity, "died") == 0)
	{
		printf(
			"%llums %ld died\n",
			get_timestamp(start_time),
			philo->position
			);
	}
	else
	{
		printf(
			"%llums %ld is %s\n",
			get_timestamp(start_time),
			philo->position,
			activity
			);
	}
}
