/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:08:29 by ychng             #+#    #+#             */
/*   Updated: 2024/01/09 05:03:19 by ychng            ###   ########.fr       */
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
	bool			stop_printing;
	int				start_time;
	pthread_mutex_t	*forks;
}	t_philo_share;

typedef struct s_philo_threads
{
	int				position;
	int				last_ate_time;
	t_philo_info	*info;
	t_philo_share	*share;
}	t_philo_threads;

// validate_input.c
void	validate_input(char **argv);

// set_info.c
void	set_info(t_philo_info *info, char **argv);

// handle_threads.c
void	handle_threads(t_philo_threads **threads,
			t_philo_info *info, t_philo_share *share);

// simulation.c
void	*simulation(void *arg);

// grab_forks.c
void	grab_forks(t_philo_threads *threads);

// release_forks.c
void	release_forks(t_philo_threads *threads);

// time_utils.c
int		get_time(void);

#endif
