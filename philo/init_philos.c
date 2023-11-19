/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:01:05 by ychng             #+#    #+#             */
/*   Updated: 2023/11/20 00:11:23 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static pthread_mutex_t	*setup_forks_mutex(size_t num_of_forks)
{
	pthread_mutex_t	*forks;
	size_t			i;

	forks = malloc(sizeof(*forks) * num_of_forks);
	if (!forks)
	{
		write_error("malloc failed for forks\n");
		exit(-1);
	}
	i = 0;
	while (i < num_of_forks)
		pthread_mutex_init(&forks[i++], NULL);
	return (forks);
}

t_philo_info	*init_philos(t_philo_config *config)
{
	pthread_mutex_t	*forks;
	t_philo_info	*philos;
	size_t			i;

	forks = setup_forks_mutex(config->num_of_philos);
	philos = malloc(sizeof(*philos) * config->num_of_philos);
	if (!philos)
	{
		write_error("malloc failed for philos\n");
		free(forks);
		exit(-1);
	}
	i = 0;
	while (i < config->num_of_philos)
	{
		philos[i] = (t_philo_info){0};
		philos[i].shared_config = config;
		philos[i].shared_forks = forks;
		i++;
	}
	return (philos);
}
