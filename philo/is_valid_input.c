/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:58:45 by ychng             #+#    #+#             */
/*   Updated: 2023/11/18 17:59:05 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static bool	is_all_digits(const char *token)
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

static bool	is_non_negative_int(const char *token)
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
