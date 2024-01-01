/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:08:29 by ychng             #+#    #+#             */
/*   Updated: 2024/01/01 16:27:33 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "sys_headers.h"
# include "libft.h"

typedef struct s_philo_config
{
	size_t	num_of_philos;
	size_t	num_of_times_to_eat;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
}	t_philo_config;

typedef struct s_philo_stats
{
	sem_t			**fork_sems;
	sem_t			*log_sem;
	sem_t			*stop_printing_sem;
	sem_t			*eating_counter_sem;
	bool			stop_printing;
	struct timeval	start_time;
}	t_philo_stats;

typedef struct s_philo_info
{
	size_t			position;
	size_t			eating_counter;
	size_t			last_meal_time;
	t_philo_config	*shared_config;
	t_philo_stats	*shared_stats;
}	t_philo_info;

// philo_bonus.c
void	write_error(char *msg);

// parse_argv.c
void	parse_argv(t_philo_config *config, char **argv);

// is_valid_input.c
bool	is_valid_input(char *token, size_t i);

// set_config.c
void	set_config(t_philo_config *config, char *token, size_t i);

// init_stats.c
void	init_stats(t_philo_stats *stats, t_philo_config config);

// init_philo.c
void	init_philo(t_philo_info *philo, t_philo_config *config,
			t_philo_stats *stats);

// cleanup.c
void	cleanup(t_philo_info philo, size_t num_of_philos);

#endif
