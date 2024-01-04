/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:08:29 by ychng             #+#    #+#             */
/*   Updated: 2024/01/04 16:12:12 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "sys_headers.h"
# include "libft_not.h"

typedef struct s_philo_info
{
	int	no_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	no_of_times_to_eat;
}	t_philo_info;

// validate_input.c
void	validate_input(char **argv);

// set_info.c
void	set_info(t_philo_info *info, char **argv);

#endif
