/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:17:12 by ychng             #+#    #+#             */
/*   Updated: 2023/11/20 22:17:34 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	write_error(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
}

void	write_timestamp(struct timeval start_time)
{
	struct timeval		current_time;
	unsigned long long	diff_in_ms;

	gettimeofday(&current_time, NULL);
	diff_in_ms = (current_time.tv_sec - start_time.tv_sec) * 1000ULL
		+ (current_time.tv_usec - start_time.tv_usec) / 1000ULL;
	printf("%llums ", diff_in_ms);
}

void	write_activity(t_philo_info *philo, char *activity)
{
	printf("%ld ", philo->position);
	if (ft_strcmp(activity, "fork") == 0)
		printf("has taken a fork\n");
	else if (ft_strcmp(activity, "died") == 0)
		printf("died\n");	
	else
		printf("is %s\n", activity);
}
