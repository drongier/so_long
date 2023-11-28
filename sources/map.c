/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:02:13 by drongier          #+#    #+#             */
/*   Updated: 2023/11/27 20:01:49 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_null(t_data *data)
{
	ft_printf("Map is empty !\n");
	free(data->buffer_map);
	exit(0);
}

char	**read_map(t_data *data, char **argv)
{
	char	*read;

	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
		print_error(5);
	data->buffer_map = ft_strdup("");
	read = get_next_line(data->fd);
	if (read == NULL)
		read_null(data);
	while (read != NULL)
	{
		data->buffer = data->buffer_map;
		data->buffer_map = ft_strjoin(data->buffer, read);
		free(read);
		free(data->buffer);
		read = get_next_line(data->fd);
	}
	data->map = ft_split(data->buffer_map, '\n');
	free(data->buffer_map);
	close(data->fd);
	return (data->map);
}
