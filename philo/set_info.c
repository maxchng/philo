/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:11:16 by ychng             #+#    #+#             */
/*   Updated: 2024/01/04 16:11:48 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static void	assign_info(t_philo_info *info, char *token, size_t i)
{
	if (i == 1)
		info->no_of_philos = ft_atoi(token);
	else if (i == 2)
		info->time_to_die = ft_atoi(token);
	else if (i == 3)
		info->time_to_eat = ft_atoi(token);
	else if (i == 4)
		info->time_to_sleep = ft_atoi(token);
	else if (i == 5)
		info->no_of_times_to_eat = ft_atoi(token);
}

void	set_info(t_philo_info *info, char **argv)
{
	int		i;
	char	*input_segment;

	*info = (t_philo_info){0};
	i = 1;
	while (argv[i])
	{
		input_segment = ft_strtok(argv[i], " ");
		while (input_segment)
		{
			assign_info(info, input_segment, i);
			input_segment = ft_strtok(NULL, " ");
		}
		i++;
	}
}
