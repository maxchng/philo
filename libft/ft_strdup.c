/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:21:54 by ychng             #+#    #+#             */
/*   Updated: 2023/11/13 15:41:42 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*new;
	size_t	i;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}
