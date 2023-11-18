/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:55:26 by ychng             #+#    #+#             */
/*   Updated: 2023/11/18 17:59:02 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

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
