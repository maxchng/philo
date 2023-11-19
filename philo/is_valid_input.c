/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:58:45 by ychng             #+#    #+#             */
/*   Updated: 2023/11/19 19:40:05 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static bool	is_all_digits(char *token)
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

static bool	meet_required_range(char *token, size_t i)
{
	long long	value;

	value = ft_atoll(token);
	if (i == 1)
		return (value >= 1 && value <= INT_MAX);
	return (value >= 0 && value <= INT_MAX);
}

bool	is_valid_input(char *token, size_t i)
{
	if (!is_all_digits(token))
	{
		write_error(token);
		write_error(" is not a whole number\n");
		return (false);
	}
	else if (!meet_required_range(token, i))
	{
		if (i == 1)
		{
			write_error("number of philos must start from 1 to 2147483647\n");
			return (false);
		}
		write_error(token);
		write_error(" must start from 0 to 2147483647\n");
		return (false);
	}
	return (true);
}
