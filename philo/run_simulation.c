/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:41:36 by ychng             #+#    #+#             */
/*   Updated: 2023/11/20 01:21:16 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	acquire_forks(t_philo_info *philo)
{
	size_t	position;
	size_t	num_of_philos;

	position = philo->position;
	num_of_philos = philo->shared_config->num_of_philos;
	pthread_mutex_lock(&philo->shared_forks[position]);
	printf("philosophers %ld has taken a fork\n", philo->position);
	pthread_mutex_lock(&philo->shared_forks[(position + 1) % num_of_philos]);	
	printf("philosophers %ld has taken a fork\n", philo->position);
}

void	release_forks(t_philo_info *philo)
{
	size_t	position;
	size_t	num_of_philos;

	position = philo->position;
	num_of_philos = philo->shared_config->num_of_philos;
	pthread_mutex_unlock(&philo->shared_forks[position]);
	pthread_mutex_unlock(&philo->shared_forks[(position + 1) % num_of_philos]);
}

void	*philo_lifecycle(void *arg)
{
	t_philo_info	*philo;

	philo = (t_philo_info *)arg;
	acquire_forks(philo);
	printf("philosophers %ld is eating\n", philo->position);
	usleep(philo->shared_config->time_to_eat);
	release_forks(philo);
	printf("philosophers %ld is sleep\n", philo->position);
	usleep(philo->shared_config->time_to_sleep);
	pthread_exit(0);
}

void	run_simulation(t_philo_info *philos)
{
	handle_threads(philos, philos->shared_config->num_of_philos);
}
