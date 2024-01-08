/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:30:54 by ychng             #+#    #+#             */
/*   Updated: 2024/01/09 05:32:27 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	start_eating(t_philo_threads *threads)
{
	threads->last_ate_time = get_time();
	print_activity("eat", threads);
}