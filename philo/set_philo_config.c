/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo_config.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:56:03 by ychng             #+#    #+#             */
/*   Updated: 2023/11/18 17:56:34 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static unsigned long long	convert_ms_to_us(int miliseconds)
{
	return ((unsigned long long)miliseconds * 1000);
}

void	set_philo_config(t_philo_config *config, char *token, size_t i)
{
	if (i == 1)
		config->number_of_philosophers = ft_atoi(token);
	else if (i == 2)
		config->time_to_die = convert_ms_to_us(ft_atoi(token));
	else if (i == 3)
		config->time_to_eat = convert_ms_to_us(ft_atoi(token));
	else if (i == 4)
		config->time_to_sleep = convert_ms_to_us(ft_atoi(token));
	else if (i == 5)
		config->number_of_times_to_eat = ft_atoi(token);
}
