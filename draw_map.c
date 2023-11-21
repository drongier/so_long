#include "so_long.h"

void	img_draw(t_data *data, void *image, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image, x * 64, y * 64);
}

int	map_draw(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == WALL)
				img_draw(data, data->spr_wall, x, y);
			else if (data->map[y][x] == COINS)
				img_draw(data, data->spr_coin, x, y);
			else if (data->map[y][x] == BG)
				img_draw(data, data->spr_bg, x, y);
			else if (data->map[y][x] == PLAYER)
				img_draw(data, data->spr_perso, x, y);
			else if (data->map[y][x] == EXIT)
				img_draw(data, data->spr_exit, x, y);
			x++;
		}
		y++;
	}
	return (0);
}