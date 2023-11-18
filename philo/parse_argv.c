/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:55:26 by ychng             #+#    #+#             */
/*   Updated: 2023/11/18 17:46:42 by ychng            ###   ########.fr       */
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

bool	is_non_negative_int(const char *token)
{
	long long	value;

	value = ft_atoll(token);
	return (value >= 0 && value <= INT_MAX);
}

bool	is_valid_input(const char *token)
{
	if (!is_all_digits(token))
	{
		write_error(token);
		write_error(" is not a whole number\n");
		return (false);
	}
	else if (!is_non_negative_int(token))
	{
		write_error(token);
		write_error(" is not in int range\n");
		return (false);
	}
	return (true);
}

unsigned long long	convert_ms_to_us(int miliseconds)
{
	return ((unsigned long long)miliseconds * 1000);
}

void	set_philo_config(t_philo_config *config, char *token, size_t i)
{
	if (i == 1)
		config->number_of_philosophers = ft_atoi(token);
	else if (i == 2)
		config->time_to_die = convert_ms_to_us(ft_atoi(token));
	else if (i == 3)
		config->time_to_eat = convert_ms_to_us(ft_atoi(token));
	else if (i == 4)
		config->time_to_sleep = convert_ms_to_us(ft_atoi(token));
	else if (i == 5)
		config->number_of_times_to_eat = ft_atoi(token);
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
