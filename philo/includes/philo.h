/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:08:29 by ychng             #+#    #+#             */
/*   Updated: 2023/11/18 18:13:17 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "sys_headers.h"
# include "libft.h"

typedef struct s_philo_config
{
	int					number_of_philosophers;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	int					number_of_times_to_eat;
}	t_philo_config;

// philo.c
void	write_error(const char *msg);

// parse_argv.c
void	parse_argv(t_philo_config *config, char **argv);

// is_valid_input.c
bool	is_valid_input(const char *token);

// set_philo_config.c
void	set_philo_config(t_philo_config *config, char *token, size_t i);

#endif
