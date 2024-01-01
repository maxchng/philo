/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:16:32 by ychng             #+#    #+#             */
/*   Updated: 2024/01/02 03:02:22 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

static void	handle_eating(t_philo_info *philo, struct timeval start_time)
{
	philo->last_meal_time = get_elapsed_time(start_time);
	write_activity(philo, "eating", start_time);
	// sem_wait(philo->shared_stats->eating_counter_sem);
	// philo->eating_counter++;
	// sem_post(philo->shared_stats->eating_counter_sem);
	if (++philo->eating_counter == philo->shared_config->num_of_times_to_eat)
		sem_post(philo->shared_stats->eating_counter_sem);
	custom_usleep(philo->shared_config->time_to_eat);
}

static void	handle_sleeping(t_philo_info *philo, struct timeval start_time)
{
	size_t	current_time;
	size_t	sleep_end_time;
	size_t	sleep_die_time;
	size_t	sleep_duration;

	current_time = get_elapsed_time(start_time);
	sleep_end_time = current_time + philo->shared_config->time_to_sleep;
	sleep_die_time = current_time + philo->shared_config->time_to_die;
	write_activity(philo, "sleeping", start_time);
	if (sleep_end_time > sleep_die_time)
	{
		sleep_duration = philo->shared_config->time_to_die;
		custom_usleep(sleep_duration);
	}
	else
	{
		sleep_duration = philo->shared_config->time_to_sleep;
		custom_usleep(sleep_duration);
	}
}

static void	handle_death(t_philo_info *philo, struct timeval start_time)
{
	size_t	time_to_sleep;
	size_t	time_to_die;

	time_to_sleep = philo->shared_config->time_to_sleep;
	time_to_die = philo->shared_config->time_to_die;
	if (time_to_sleep > time_to_die)
	{
		write_activity(philo, "died", start_time);
		exit(0);
	}
}

static void	handle_thinking(t_philo_info *philo, struct timeval start_time)
{
	write_activity(philo, "thinking", start_time);
}

void	run_simulation(t_philo_info *philo)
{
	struct timeval	start_time;

	start_time = philo->shared_stats->start_time;
	while (1)
	{
		acquire_forks(philo, start_time);
		handle_eating(philo, start_time);
		release_forks(philo);
		handle_sleeping(philo, start_time);
		handle_death(philo, start_time);
		handle_thinking(philo, start_time);
	}
}
