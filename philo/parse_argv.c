/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:55:26 by ychng             #+#    #+#             */
/*   Updated: 2023/11/14 17:03:02 by ychng            ###   ########.fr       */
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

void	parse_argv(char **argv)
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
			token = ft_strtok(NULL, " ");
		}
		i++;
	}
}
