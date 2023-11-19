/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:01:05 by ychng             #+#    #+#             */
/*   Updated: 2023/11/19 20:56:10 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

t_philo_info	*init_philos(t_philo_config *config)
{
	t_philo_info	*philos;
	size_t			i;

	philos = malloc(sizeof(*philos) * config->num_of_philos);
	if (!philos)
	{
		write_error("malloc failed for philos\n");
		exit(-1);
	}
	i = 0;
	while (i < config->num_of_philos)
	{
		philos[i] = (t_philo_info){0};
		philos[i].shared_config = config;
		i++;
	}
	return (philos);
}
