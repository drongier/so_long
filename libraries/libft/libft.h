/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:54:24 by drongier          #+#    #+#             */
/*   Updated: 2023/11/28 14:47:52 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*ft_itoa(int n);

#endif
