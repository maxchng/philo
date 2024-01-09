/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:59:28 by ychng             #+#    #+#             */
/*   Updated: 2024/01/09 12:08:04 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int64_t	get_time(void)
{
	struct timeval	current_time;
	int64_t			miliseconds;

	gettimeofday(&current_time, NULL);
	miliseconds = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (miliseconds);
}

void	custom_usleep(int time)
{
	int64_t	start_of_this_function;

	start_of_this_function = get_time();
	while ((get_time() - start_of_this_function) < time)
		usleep(50);
}
