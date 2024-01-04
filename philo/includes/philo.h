/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:08:29 by ychng             #+#    #+#             */
/*   Updated: 2024/01/04 17:34:36 by ychng            ###   ########.fr       */
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

typedef struct s_philo_share
{
	pthread_t	*tids;
}	t_philo_share;

typedef struct s_philo_threads
{
	int	position;
	int	start_time;
}	t_philo_threads;

typedef struct s_philo_main
{
	t_philo_info	*info;
	t_philo_share	*share;
	t_philo_threads	*threads;
}	t_philo_main;

// validate_input.c
void	validate_input(char **argv);

// set_info.c
void	set_info(t_philo_info *info, char **argv);

// handle_threads.c
void	handle_threads(t_philo_main *main);

// simulation.c
void	*simulation(void *arg);

#endif
