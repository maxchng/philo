/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:56:03 by ychng             #+#    #+#             */
/*   Updated: 2024/01/01 15:53:58 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	set_config(t_philo_config *config, char *token, size_t i)
{
	if (i == 1)
		config->num_of_philos = ft_atoi(token);
	else if (i == 2)
		config->time_to_die = ft_atoi(token);
	else if (i == 3)
		config->time_to_eat = ft_atoi(token);
	else if (i == 4)
		config->time_to_sleep = ft_atoi(token);
	else if (i == 5)
		config->num_of_times_to_eat = ft_atoi(token);
}
