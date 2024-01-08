/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 02:38:19 by ychng             #+#    #+#             */
/*   Updated: 2024/01/09 02:41:37 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	start_eating(t_philo_threads *threads)
{
	threads->last_ate_time = get_time();
	printf("%d %d is eating\n", threads->last_ate_time, threads->position);
}
