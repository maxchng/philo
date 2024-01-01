/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:01:05 by ychng             #+#    #+#             */
/*   Updated: 2024/01/01 16:01:30 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	init_philo(t_philo_info *philo, t_philo_config *config,
	t_philo_stats *stats)
{
	*philo = (t_philo_info){0};
	philo->shared_config = config;
	philo->shared_stats = stats;
}
