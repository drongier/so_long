/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:34:35 by drongier          #+#    #+#             */
/*   Updated: 2023/11/27 18:38:23 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libraries/minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.move_count = 0;
	if (argc != 2)
	{
		ft_printf("Error !! Try : so_long + mapX.ber\n");
		return (0);
	}
	if (!read_map(&data, argv))
		return (0);
	check_errors(&data);
	init_map(&data);
	mlx_hook(data.win_ptr, 2, 1L << 0, &handle_key, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	mlx_loop(data.mlx_ptr);
	exit_game(&data);
	return (0);
}
