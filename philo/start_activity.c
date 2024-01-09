/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_activity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:30:54 by ychng             #+#    #+#             */
/*   Updated: 2024/01/09 12:02:45 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	start_eating(t_philo_threads *threads)
{
	threads->last_ate_time = get_time();
	print_activity("eat", threads);
	custom_usleep(threads->info->time_to_eat);
}

void	start_sleeping(t_philo_threads *threads)
{
	print_activity("sleep", threads);
	custom_usleep(threads->info->time_to_sleep);	
}

void	start_thinking(t_philo_threads *threads)
{
	print_activity("think", threads);
}
