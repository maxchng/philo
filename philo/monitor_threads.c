/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 01:40:44 by ychng             #+#    #+#             */
/*   Updated: 2024/01/09 02:29:20 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	monitor_threads(t_philo_threads **threads)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < threads[0]->info->no_of_philos)
		{
			if ((get_time() - threads[i]->last_ate_time) > threads[0]->info->time_to_die)
			{
				threads[0]->share->stop_printing = true;
				return ;
			}
			i++;
		}
	}
}
