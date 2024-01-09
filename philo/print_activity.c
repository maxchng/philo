/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_activity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:20:45 by ychng             #+#    #+#             */
/*   Updated: 2024/01/09 12:12:35 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static void	print_fork(t_philo_threads *threads)
{
	int64_t	elapsed_time;

	elapsed_time = get_time() - threads->share->start_time;
	printf("%ld %d has taken a fork\n", elapsed_time, threads->position);
}

static void	print_eat(t_philo_threads *threads)
{
	int64_t	elapsed_time;

	elapsed_time = get_time() - threads->share->start_time;
	printf("%ld %d is eating\n", elapsed_time, threads->position);
}

static void	print_sleep(t_philo_threads *threads)
{
	int64_t	elapsed_time;

	elapsed_time = get_time() - threads->share->start_time;
	printf("%ld %d is sleeping\n", elapsed_time, threads->position);
}

static void	print_think(t_philo_threads *threads)
{
	int64_t	elapsed_time;

	elapsed_time = get_time() - threads->share->start_time;
	printf("%ld %d is thinking\n", elapsed_time, threads->position);
}

static void	print_die(t_philo_threads *threads)
{
	int64_t	elapsed_time;

	elapsed_time = get_time() - threads->share->start_time;
	printf("%ld %d died\n", elapsed_time, threads->position);
}

void	print_activity(char *activity, t_philo_threads *threads)
{
	pthread_mutex_lock(&threads->share->print);
	if (ft_strcmp(activity, "fork") == 0)
		print_fork(threads);
	else if (ft_strcmp(activity, "eat") == 0)
		print_eat(threads);
	else if (ft_strcmp(activity, "sleep") == 0)
		print_sleep(threads);
	else if (ft_strcmp(activity, "think") == 0)
		print_think(threads);
	else if (ft_strcmp(activity, "die") == 0)
		print_think(threads);
	pthread_mutex_unlock(&threads->share->print);
}
