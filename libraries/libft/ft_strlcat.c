/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:49:25 by drongier          #+#    #+#             */
/*   Updated: 2023/11/28 14:49:30 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	destiny;
	size_t	source;
	size_t	result;

	if (((!src || !dst) && !size))
		return (0);
	i = 0;
	result = 0;
	destiny = ft_strlen(dst);
	source = ft_strlen(src);
	if (size > destiny)
		result = source + destiny;
	else
		result = source + size;
	while (size > (destiny + 1) && src[i] != '\0')
	{
		dst[destiny] = src[i];
		destiny++;
		i++;
	}
	dst[destiny] = '\0';
	return (result);
}
