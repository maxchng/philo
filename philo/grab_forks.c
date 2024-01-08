/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:50:10 by ychng             #+#    #+#             */
/*   Updated: 2024/01/09 02:27:22 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	grab_forks(t_philo_threads *threads)
{
	int	left_fork;
	int	right_fork;

	left_fork = threads->position;
	right_fork = (threads->position + 1) % threads->info->no_of_philos;
	pthread_mutex_lock(&threads->share->forks[left_fork]);
	printf("%d %d has taken a fork\n", get_time(), threads->position);
	pthread_mutex_lock(&threads->share->forks[right_fork]);
	printf("%d %d has taken a fork\n", get_time(), threads->position);
}
