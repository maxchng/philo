/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:08:29 by ychng             #+#    #+#             */
/*   Updated: 2024/01/01 17:35:58 by ychng            ###   ########.fr       */
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

// create_processes.c
void	create_processes(t_philo_info *philo, size_t num_of_philos);

// monitor_simulation.c
void	*monitor_simulation(void *arg);

// run_simulation.c
void	run_simulation(t_philo_info *philo);

// acquire_forks.c
void	acquire_forks(t_philo_info *philo, struct timeval start_time);

// release_forks.c
void	unlock_forks(t_philo_info *philo, size_t fork1,
			size_t fork2);
void	release_forks(t_philo_info *philo);

// write_activity.c
void	write_activity(t_philo_info *philo, char *activity,
			struct timeval start_time);

// time_utils.c
void	custom_usleep(size_t activity_time);
size_t	get_elapsed_time(struct timeval start_time);

// cleanup.c
void	cleanup(t_philo_info *philo, size_t num_of_philos);

#endif
