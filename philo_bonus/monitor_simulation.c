/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:49:16 by ychng             #+#    #+#             */
/*   Updated: 2024/01/01 17:33:43 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

static bool	check_exit_condition(t_philo_info *philo)
{
	size_t	num_of_times_to_eat;
	size_t	eating_counter;
	bool	stop_printing;

	num_of_times_to_eat = philo->shared_config->num_of_times_to_eat;
	sem_wait(philo->shared_stats->eating_counter_sem);
	eating_counter = philo->eating_counter;
	sem_post(philo->shared_stats->eating_counter_sem);
	sem_wait(philo->shared_stats->stop_printing_sem);
	stop_printing = philo->shared_stats->stop_printing;
	sem_post(philo->shared_stats->stop_printing_sem);
	if (stop_printing)
		return (true);
	return (num_of_times_to_eat != 0 && eating_counter >= num_of_times_to_eat);
}

void	*monitor_simulation(void *arg)
{
	t_philo_info	*philo;

	philo = (t_philo_info *)arg;
	while (1)
	{
		if (check_exit_condition(philo))
		{
			sem_wait(philo->shared_stats->stop_printing_sem);
			philo->shared_stats->stop_printing = true;
			sem_post(philo->shared_stats->stop_printing_sem);
			pthread_exit(0);
		}
	}
}
