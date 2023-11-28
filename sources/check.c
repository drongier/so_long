/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:07:59 by drongier          #+#    #+#             */
/*   Updated: 2023/11/28 11:15:12 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	data_player(t_data *data, int i, int j)
{
	data->player_count++;
	data->player_x = i;
	data->player_y = j;
}

int	is_all_p(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != 'P' && 
			data->map[i][j] != 'E' && data->map[i][j] != 'C' && 
			data->map[i][j] != '0' && data->map[i][j] != '1')
				print_error(1);
			if (data->map[i][j] == 'P')
				data_player(data, i, j);
			else if (data->map[i][j] == 'C')
				data->coins_count++;
			else if (data->map[i][j] == 'E')
				data->exit_count++;
			j++;
		}
		i++;
	}
	return (1);
}

int	is_map_rectangular(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			print_error(2);
		i++;
	}
	return (1);
}

int	is_wall(char **map)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	while (map[i] != NULL)
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map [0][j] != '1' || map[i - 1][j] != '1')
			print_error(3);
		++j; 
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (map [i][0] != '1' || map[i][len - 1] != '1')
			print_error(3);
		i++;
	}
	return (1);
}

int	*check_errors(t_data *data)
{
	data->coins_count = 0;
	data->exit_count = 0;
	data->player_count = 0;
	is_map_rectangular(data->map);
	is_wall(data->map);
	is_all_p(data);
	if (data->player_count != 1 || data->coins_count == 0 
		|| data->exit_count != 1)
		print_error(4);
	return (0);
}
