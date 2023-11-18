/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_requirements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:11:31 by ychng             #+#    #+#             */
/*   Updated: 2023/11/18 20:14:57 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

bool	meets_philo_requirements(t_philo_config *config)
{
	if (config->number_of_philosophers == 0)
	{
		write_error("Number of philosophers must start from 1 to 2147483647\n");
		return (false);
	}
	return (true);
}
