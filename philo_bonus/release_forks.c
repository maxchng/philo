/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:58:08 by ychng             #+#    #+#             */
/*   Updated: 2024/01/11 21:37:29 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	release_forks(t_philo_info *philo)
{
	sem_post(philo->shared_stats->fork_sems);
	sem_post(philo->shared_stats->fork_sems);
}
