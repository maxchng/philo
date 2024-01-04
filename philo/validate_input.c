/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:51:56 by ychng             #+#    #+#             */
/*   Updated: 2024/01/04 16:16:55 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static bool	is_positive_whole_number(char *input_segment)
{
	int	i;

	if (input_segment[0] == '\0')
		return (false);
	i = -1;
	while (input_segment[++i])
	{
		if (!(input_segment[i] >= '0' && input_segment[i] <= '9'))
			return (false);
	}
	return (true);
}

static bool	is_within_range(char *input_segment, int i)
{
	long long	value;

	value = ft_atoll(input_segment);
	if (i == 1 || i == 5)
		return (value >= 1 && value <= INT_MAX);
	return (value >= 0 && value <= INT_MAX);
}

static bool	is_valid_input(char *input_segment, int i)
{
	char	*error_message;

	if (!is_positive_whole_number(input_segment))
	{
		printf("%s is not a positive whole number", input_segment);
		return (false);
	}
	else if (!is_within_range(input_segment, i))
	{
		if (i == 1 || i == 5)
			error_message = "is not within the range of 1 to 2147483647\n";
		else
			error_message = "is not within the range of 0 to 2147483647\n";
		printf("%s %s\n", input_segment, error_message);
		return (false);
	}
	return (true);
}

void	validate_input(char **argv)
{
	int		i;
	char	*arg_copy;
	char	*input_segment;

	i = 1;
	while (argv[i])
	{
		arg_copy = ft_strdup(argv[i]);
		input_segment = ft_strtok(arg_copy, " ");
		while (input_segment)
		{
			if (is_valid_input(input_segment, i))
			{
				free(arg_copy);
				exit(-1);
			}
			input_segment = ft_strtok(NULL, " ");
		}
		free(arg_copy);
		i++;
	}
}
