#include "so_long.h"

static void img_init(t_data *data)
{
    data->spr_wall = mlx_xpm_file_to_image(data->mlx_ptr, "assets/wall.xpm", &data->img_width, &data->img_height);
    data->spr_coin = mlx_xpm_file_to_image(data->mlx_ptr, "assets/coin.xpm", &data->img_width, &data->img_height);
    data->spr_perso = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player.xpm", &data->img_width, &data->img_height);
    data->spr_exit = mlx_xpm_file_to_image(data->mlx_ptr, "assets/exit.xpm", &data->img_width, &data->img_height);
    data->spr_bg = mlx_xpm_file_to_image(data->mlx_ptr, "assets/bg.xpm", &data->img_width, &data->img_height);
}

static void size_windo(t_data *data)
{
    int i;

    data->win_width = ft_strlen(data->map[0]) * 64;
    i = 0;
    while (data->map[i] != NULL)
        i++;
    data->win_height = i * 64;
}

void init_map(t_data *data)
{
	data->mlx_ptr = mlx_init();
    size_windo(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width, data->win_height, "so_long :)");
    img_init(data);
    map_draw(data);
}