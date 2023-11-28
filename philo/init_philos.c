/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:01:05 by ychng             #+#    #+#             */
/*   Updated: 2023/11/28 16:17:35 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static pthread_mutex_t	*setup_mutex(size_t num_of_mutex)
{
	pthread_mutex_t	*mutex;
	size_t			i;

	mutex = malloc(sizeof(*mutex) * num_of_mutex);
	if (!mutex)
	{
		write_error("malloc failed for mutex\n");
		exit(-1);
	}
	i = 0;
	while (i < num_of_mutex)
		pthread_mutex_init(&mutex[i++], NULL);
	return (mutex);
}

t_philo_info	*init_philos(t_philo_config *config)
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*activity;
	t_philo_info	*philos;
	size_t			i;

	forks = setup_mutex(config->num_of_philos);
	activity = setup_mutex(1);
	philos = malloc(sizeof(*philos) * config->num_of_philos);
	if (!philos)
	{
		write_error("malloc failed for philos\n");
		free(forks);
		free(activity);
		exit(-1);
	}
	i = 0;
	while (i < config->num_of_philos)
	{
		philos[i] = (t_philo_info){0};
		philos[i].shared_config = config;
		philos[i].shared_forks = forks;
		philos[i].shared_activity = activity;
		i++;
	}
	return (philos);
}
