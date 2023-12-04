/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:16:50 by drongier          #+#    #+#             */
/*   Updated: 2023/11/28 13:22:54 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	stay_pos(t_data *data)
{
	data->player_x = data->prev_x;
	data->player_y = data->prev_y;
	map_draw(data);
}

void	switch_bg(t_data *data, int nx, int ny)
{
	data->map[data->prev_x][data->prev_y] = '0';
	data->player_x = nx;
	data->player_y = ny;
	data->map[nx][ny] = 'P';
	map_draw(data);
}

void	player_move(t_data *data, int next_y, int next_x)
{
	if ((data->map[next_x][next_y] == 'C') 
			|| (data->map[next_x][next_y] == '0'))
	{
		if (data->map[next_x][next_y] == 'C')
			data->coins_count--;
		switch_bg(data, next_x, next_y);
	}
	if (data->map[next_x][next_y] == '1')
		stay_pos(data);
	if (data->map[next_x][next_y] == 'E')
	{
		if (data->coins_count == 0)
		{
			ft_printf("YOU WIN !\n");
			ft_printf("Moves : %d\n", data->move_count);
			exit(0);
		}
		ft_printf("%d coins missing !!\n", data->coins_count);
		stay_pos(data);
	}
}

int	handle_count(t_data *data)
{
	char	*message;
	char	*count;

	count = ft_itoa(data->move_count);
	message = ft_strjoin("Move count: ", count);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 
		20, 20, 0xFFFFFF, message);
	free(count);
	free(message);
	return (0);
}

int	handle_key(int keycode, t_data *data)
{
	data->prev_x = data->player_x;
	data->prev_y = data->player_y;
	if (keycode == XK_w || keycode == XK_s
		|| keycode == XK_a || keycode == XK_d)
		data->move_count += 1;
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	else if (keycode == XK_w)
		player_move(data, data->player_y, data->player_x -= 1);
	else if (keycode == XK_s)
		player_move(data, data->player_y, data->player_x += 1);
	else if (keycode == XK_a)
		player_move(data, data->player_y -= 1, data->player_x);
	else if (keycode == XK_d)
		player_move(data, data->player_y += 1, data->player_x);
	handle_count(data);
	return (0);
}
