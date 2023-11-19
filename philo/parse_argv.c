/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:55:26 by ychng             #+#    #+#             */
/*   Updated: 2023/11/19 23:31:23 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static void	validate_argv(char **argv)
{
	size_t	i;
	char	*token;
	char	*duplicate;

	i = 1;
	while (argv[i])
	{
		duplicate = ft_strdup(argv[i]);
		token = ft_strtok(duplicate, " ");
		while (token)
		{
			if (!is_valid_input(token, i))
			{
				free(duplicate);
				exit(-1);
			}
			token = ft_strtok(NULL, " ");
		}
		free(duplicate);
		i++;
	}
}

static void	update_config(t_philo_config *config, char **argv)
{
	size_t	i;
	char	*token;

	i = 1;
	while (argv[i])
	{
		token = ft_strtok(argv[i], " ");
		while (token)
		{
			set_config(config, token, i);
			token = ft_strtok(NULL, " ");
		}
		i++;
	}
}

void	parse_argv(t_philo_config *config, char **argv)
{
	validate_argv(argv);
	update_config(config, argv);
}
