/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:08:29 by ychng             #+#    #+#             */
/*   Updated: 2023/11/18 17:59:22 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "sys_headers.h"
# include "libft.h"

// philo.c
void	write_error(const char *msg);

// parse_argv.c
void	parse_argv(t_philo_config *config, char **argv);

// is_valid_input.c
bool	is_valid_input(const char *token);

// set_philo_config.c
void	set_philo_config(t_philo_config *config, char *token, size_t i);

#endif
