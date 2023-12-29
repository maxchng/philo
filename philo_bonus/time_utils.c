/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 07:02:40 by ychng             #+#    #+#             */
/*   Updated: 2023/12/29 16:20:27 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

static size_t	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

/*	CAN'T USE ELAPSED TIME BECUZ
	IM BASICALLY REPLACING USLEEP WITH MY OWN
	SO IM STARTING TO COUNT FROM THE BEGINNING OF THIS FUNCTION
	THEN KEEP MINUSING UNTIL ITS MORE THAN THE TIME
*/
void	custom_usleep(size_t activity_time)
{
	size_t	beginning_of_usleep;

	beginning_of_usleep = get_time();
	while ((get_time() - beginning_of_usleep) < activity_time)
		usleep(50);
}

size_t	get_elapsed_time(struct timeval start_time)
{
	size_t	start_time_ms;
	size_t	diff_in_ms;

	start_time_ms = (start_time.tv_sec * 1000) + (start_time.tv_usec / 1000);
	diff_in_ms = get_time() - start_time_ms;
	return (diff_in_ms);
}
