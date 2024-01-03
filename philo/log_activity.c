/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_activity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:17:12 by ychng             #+#    #+#             */
/*   Updated: 2024/01/03 23:56:51 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

// static void	print_activity(t_philo_info *philo, char *activity,
// 	struct timeval start_time)
// {
// 	if (ft_strcmp(activity, "fork") == 0)
// 	{
// 		printf("%ld %ld has taken a fork\n",
// 			get_elapsed_time(start_time),
// 			philo->position
// 			);
// 	}
// 	else if (ft_strcmp(activity, "died") == 0)
// 	{
// 		printf("%ld %ld died\n",
// 			get_elapsed_time(start_time),
// 			philo->position
// 			);
// 		philo->shared_stats->stop_printing = true;
// 	}
// 	else
// 	{
// 		printf("%ld %ld is %s\n",
// 			get_elapsed_time(start_time),
// 			philo->position, activity
// 			);
// 	}
// }

// void	write_activity(t_philo_info *philo, char *activity,
// 	struct timeval start_time)
// {
// 	pthread_mutex_lock(philo->shared_stats->log_mutex);
// 	pthread_mutex_lock(philo->shared_stats->stop_printing_mutex);
// 	if (!philo->shared_stats->stop_printing)
// 		print_activity(philo, activity, start_time);
// 	pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
// 	pthread_mutex_unlock(philo->shared_stats->log_mutex);
// }

void	write_fork_activity(t_philo_info *philo, struct timeval start_time)
{
	printf("%ld %ld has taken a fork\n",
		get_elapsed_time(start_time),
		philo->position
		);
}

void	write_died_activity(t_philo_info *philo, struct timeval start_time)
{
	philo->shared_stats->stop_printing = true;
	printf("%ld %ld died\n",
		get_elapsed_time(start_time),
		philo->position
		);
}

void	write_general_activity(t_philo_info *philo, char *activity,
	struct timeval start_time)
{
	printf("%ld %ld is %s\n",
		get_elapsed_time(start_time),
		philo->position, activity
		);
}

void	log_activity(t_philo_info *philo, char *activity,
	struct timeval start_time)
{
	pthread_mutex_lock(philo->shared_stats->stop_printing_mutex);
	if (philo->shared_stats->stop_printing)
	{
		pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
		return ;
	}
	pthread_mutex_unlock(philo->shared_stats->stop_printing_mutex);
	pthread_mutex_lock(philo->shared_stats->log_mutex);
	if (ft_strcmp(activity, "fork") == 0)
		write_fork_activity(philo, start_time);
	else if (ft_strcmp(activity, "died") == 0)
		write_died_activity(philo, start_time);
	else
		write_general_activity(philo, activity, start_time);
	pthread_mutex_unlock(philo->shared_stats->log_mutex);
}