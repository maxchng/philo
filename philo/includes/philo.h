/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:08:29 by ychng             #+#    #+#             */
/*   Updated: 2024/01/03 23:18:55 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "sys_headers.h"
# include "libft_not.h"

typedef struct s_philo_config
{
	size_t				num_of_philos;
	size_t				num_of_times_to_eat;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
}	t_philo_config;

typedef struct s_philo_stats
{
	pthread_mutex_t		*fork_mutexes;
	pthread_mutex_t		*log_mutex;
	pthread_mutex_t		*stop_printing_mutex;
	pthread_mutex_t		*eating_counter_mutex;
	bool				stop_printing;
	struct timeval		start_time;
}	t_philo_stats;

typedef struct s_philo_info
{
	size_t				position;
	size_t				eating_counter;
	size_t				last_meal_time;
	t_philo_config		*shared_config;
	t_philo_stats		*shared_stats;
}	t_philo_info;

// philo.c
void	write_error(char *msg);

// parse_argv.c
void	parse_argv(t_philo_config *config, char **argv);

// setup_stats.c
void	setup_stats(t_philo_stats *stats, t_philo_config config);

// is_valid_input.c
bool	is_valid_input(char *token, size_t i);

// set_config.c
void	set_config(t_philo_config *config, char *token, size_t i);

// create_philos.c
void	create_philos(t_philo_info **philos, t_philo_config *config,
			t_philo_stats *stats);

// philo_lifecycle.c
void	*philo_lifecycle(void *arg);

// acquire_for	
void	acquire_forks(t_philo_info *philo, struct timeval start_time);

// release_forks.c
void	release_forks(t_philo_info *philo);
void	unlock_forks(t_philo_info *philo, size_t fork1, size_t fork2);

// manage_threads.c
void	manage_threads(t_philo_info *philos, size_t num_of_philos);

// monitor_threads.c
void	monitor_threads(t_philo_info *philos, size_t num_of_philos);

// log_activity.c
void	log_activity(t_philo_info *philo, char *activity,
			struct timeval start_time);

// time_utils.c
void	custom_usleep(size_t activity_time);
size_t	get_elapsed_time(struct timeval start_time);

// cleanup.c
void	free_mutexes(t_philo_stats *stats);
void	cleanup(t_philo_info *philos);

#endif
