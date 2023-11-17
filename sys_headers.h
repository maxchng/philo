/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_headers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:00:56 by ychng             #+#    #+#             */
/*   Updated: 2023/11/17 21:30:45 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYS_HEADERS_H
# define SYS_HEADERS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_philo_config
{
	int	number_of_philosophers;
    int	time_to_die;
    int	time_to_eat;
    int	time_to_sleep;
    int	number_of_times_to_eat;
}	t_philo_config;

#endif
