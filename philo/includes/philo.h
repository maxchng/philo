/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:08:29 by ychng             #+#    #+#             */
/*   Updated: 2023/11/28 16:15:00 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "sys_headers.h"
# include "libft.h"

typedef struct s_philo_config
{
	size_t				num_of_philos;
	size_t				num_of_times_to_eat;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
}	t_philo_config;

typedef struct s_philo_info
{
	bool				is_dead;
	size_t				position;
	size_t				num_of_times_ate;
	size_t				last_meal_time;
	t_philo_config		*shared_config;
	pthread_mutex_t		*shared_forks;
	pthread_mutex_t		*shared_activity;
}	t_philo_info;

// philo.c
void				write_error(char *msg);

// parse_argv.c
void				parse_argv(t_philo_config *config, char **argv);

// is_valid_input.c
bool				is_valid_input(char *token, size_t i);

// set_config.c
void				set_config(t_philo_config *config, char *token, size_t i);

// init_philos.c
t_philo_info		*init_philos(t_philo_config *config);

// run_simulation.c
void				run_simulation(t_philo_info *philos);
void				*philo_lifecycle(void *arg);

// handle_threads.c
void				handle_threads(t_philo_info *philos, size_t num_of_philos);

// philo_lifecycle.c
size_t				get_timestamp_ms(struct timeval start_time);
void				write_activity(t_philo_info *philo, char *activity,
						struct timeval start_time);

#endif
