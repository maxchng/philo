/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:08:29 by ychng             #+#    #+#             */
/*   Updated: 2023/11/19 18:42:50 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "sys_headers.h"
# include "libft.h"

typedef struct s_philo_stats
{
	pthread_mutex_t	*forks;
}	t_philo_stats;

typedef struct s_philo_config
{
	size_t				number_of_philosophers;
	size_t				number_of_times_to_eat;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
}	t_philo_config;

typedef struct s_philo_info
{
	size_t			position;
	size_t			num_of_times_ate;
	t_philo_stats	*shared_stats;
	t_philo_config	*shared_config;
}	t_philo_info;

// philo.c
void	write_error(const char *msg);

// parse_argv.c
void	parse_argv(t_philo_config *config, char **argv);

// is_valid_input.c
bool	is_valid_input(const char *token);

// set_philo_config.c
void	set_philo_config(t_philo_config *config, char *token, size_t i);

// philo_requirements.c
bool	meets_philo_requirements(t_philo_config *config);

#endif
