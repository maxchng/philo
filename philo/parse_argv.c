/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:55:26 by ychng             #+#    #+#             */
/*   Updated: 2023/11/17 22:40:41 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

bool	is_all_digits(const char *token)
{
	int	i;

	if (token[0] == '\0')
		return (false);
	i = -1;
	while (token[++i])
	{
		if (!(token[i] >= '0' && token[i] <= '9'))
			return (false);
	}
	return (true);
}

bool	is_in_int_range(const char *token)
{
	long long	value;

	value = ft_atoll(token);
	return (value >= INT_MIN && value <= INT_MAX);
}

bool	is_valid_input(const char *token)
{
	if (!is_all_digits(token))
	{
		write_error(token);
		write_error(" is not a whole number\n");
		return (false);
	}
	else if (!is_in_int_range(token))
	{
		write_error(token);
		write_error(" is not in int range\n");
		return (false);
	}
	return (true);
}

void	set_philo_config(t_philo_config *config, char *token, size_t i)
{
	if (i == 1)
		config->number_of_philosophers = ft_atoll(token);
	else if (i == 2)
		config->time_to_die = ft_atoll(token);
	else if (i == 3)
		config->time_to_eat = ft_atoll(token);
	else if (i == 4)
		config->time_to_sleep = ft_atoll(token);
	else if (i == 5)
		config->number_of_times_to_eat = ft_atoll(token);
}

void	parse_argv(t_philo_config *config, char **argv)
{
	size_t	i;
	char	*token;

	i = 1;
	while (argv[i])
	{
		token = ft_strtok(argv[i], " ");
		while (token != NULL)
		{
			if (!is_valid_input(token))
				exit(-1);
			set_philo_config(config, token, i);
			token = ft_strtok(NULL, " ");
		}
		i++;
	}
}
