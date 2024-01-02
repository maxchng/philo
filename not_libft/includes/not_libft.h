/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_libft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:00:36 by ychng             #+#    #+#             */
/*   Updated: 2024/01/02 12:11:54 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOT_LIBFT_H
# define NOT_LIBFT_H

# include "sys_headers.h"

size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *str, int c);
char		*ft_strtok(char *str, const char *delim);
char		*ft_strdup(const char *str);
char		*ft_strjoin(const char *s1, const char *s2, const char *delim);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(const char *str, const char *delim);
int			ft_atoi(const char *str);
long long	ft_atoll(const char *str);
char		*ft_itoa(int n);

#endif
