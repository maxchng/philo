/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:55:26 by ychng             #+#    #+#             */
/*   Updated: 2023/11/13 19:16:59 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_all_digits(const char *token)
{
	int	i;

	if (token[0] == '\0')
		return (false);
	i = -1;
	while (token[++i])
	{
		if (!is_digit(token[i]))
			return (false);
	}
	return (true);
}

bool	is_in_int_range(const char *token)
{
	long long	value;

	if (!is_all_digits(token))
		return (false);
	value = ft_atoll(token);
	return (value >= INT_MIN && value <= INT_MAX);
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
			if (!is_in_int_range(token))
				write_error("is not in int range\n");
			token = ft_strtok(NULL, " ");
		}
		i++;
	}
}
