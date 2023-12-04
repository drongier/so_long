/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:01:41 by drongier          #+#    #+#             */
/*   Updated: 2023/06/22 16:52:52 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	src_len;

	src_len = ft_strlen(s) + 1;
	dest = (char *) malloc(src_len);
	if (s != NULL && dest != NULL)
		ft_strlcpy(dest, s, src_len);
	return (dest);
}

// char	*ft_strdup(const char *s1)
// {
// 	int		s_len;
// 	char	*dup;

// 	s_len = ft_strlen(s1);
// 	dup = (char *)malloc((s_len + 1) * sizeof(char));
// 	if (!dup)
// 		return (NULL);
// 	dup[s_len] = 0;
// 	while (s_len >= 0)
// 	{
// 		dup[s_len] = s1[s_len];
// 		s_len--;
// 	}
// 	return (dup);
// }
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    const char *original = "Hello, world!";

    char *copy = ft_strdup(original);
    if (copy != NULL) {
        printf("Copie : %s\n", copy);

        free(copy);
    }

    return 0;
}
*/
