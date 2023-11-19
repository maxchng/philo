/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:41:36 by ychng             #+#    #+#             */
/*   Updated: 2023/11/20 03:24:22 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

unsigned long long current_timestamp(void)
{
	struct timeval	timestamp;

	gettimeofday(&timestamp, NULL);
	return (timestamp.tv_usec / 1000ULL);
}

void	log_activity(t_philo_info *philo, char *activity)
{
	unsigned long long	timestamp_ms;
	size_t				position;

	timestamp_ms = current_timestamp();
	position = philo->position;
	if (ft_strcmp(activity, "fork") == 0)
		printf("%llu %ld has taken a %s\n", timestamp_ms, position, activity);
	else if (ft_strcmp(activity, "died") == 0)
		printf("%llu %ld %s\n", timestamp_ms, position, activity);
	else
		printf("%llu %ld is %s\n", timestamp_ms, position, activity);
}

void	acquire_forks(t_philo_info *philo)
{
	size_t	position;
	size_t	num_of_philos;

	position = philo->position;
	num_of_philos = philo->shared_config->num_of_philos;
	pthread_mutex_lock(&philo->shared_forks[position]);
	log_activity(philo, "fork");
	pthread_mutex_lock(&philo->shared_forks[(position + 1) % num_of_philos]);	
	log_activity(philo, "fork");
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

unsigned long long	time_since_last_meal(struct timeval last_meal_time)
{
	return (current_timestamp() - (last_meal_time.tv_usec / 1000ULL));
}

void	*philo_lifecycle(void *arg)
{
	t_philo_info	*philo;
	size_t			time_to_die;
	struct timeval	last_meal_time;

	philo = (t_philo_info *)arg;
	time_to_die = philo->shared_config->time_to_die;
	gettimeofday(&last_meal_time, NULL);
	acquire_forks(philo);
	if (time_since_last_meal(last_meal_time) > (unsigned long long)time_to_die)
	{
		log_activity(philo, "died");
		pthread_exit(-1);		
	}
	log_activity(philo, "eating");
	usleep(philo->shared_config->time_to_eat);
	release_forks(philo);
	log_activity(philo, "sleeping");
	usleep(philo->shared_config->time_to_sleep);
	pthread_exit(0);
}

void	run_simulation(t_philo_info *philos)
{
	handle_threads(philos, philos->shared_config->num_of_philos);
}
