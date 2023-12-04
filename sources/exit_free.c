/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:12:20 by drongier          #+#    #+#             */
/*   Updated: 2023/11/28 13:15:36 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	exit_game(t_data *data)
{
	free_map(data);
	mlx_destroy_image(data->mlx_ptr, data->spr_bg);
	mlx_destroy_image(data->mlx_ptr, data->spr_coin);
	mlx_destroy_image(data->mlx_ptr, data->spr_perso);
	mlx_destroy_image(data->mlx_ptr, data->spr_wall);
	mlx_destroy_image(data->mlx_ptr, data->spr_exit);
	close_window(data);
	mlx_loop_end(data->mlx_ptr);
}
