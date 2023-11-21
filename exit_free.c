#include "so_long.h"

void free_map(char **map)
{
    int i;

    i = 0;
    while (map[i] != NULL)
    {
        free(map[i]);
        i++;
    }
    free(map);
}


void exit_game(t_data *data)
{
    free_map(data->map);
    mlx_destroy_image(data->mlx_ptr, data->spr_bg);
    mlx_destroy_image(data->mlx_ptr, data->spr_coin);
    mlx_destroy_image(data->mlx_ptr, data->spr_perso);
    mlx_destroy_image(data->mlx_ptr, data->spr_wall);
    mlx_destroy_image(data->mlx_ptr, data->spr_exit);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    free(data->map);
    mlx_loop_end(data->mlx_ptr);
}