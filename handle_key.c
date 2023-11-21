#include "so_long.h"

void player_move(t_data *data, int next_y, int next_x)
{
    int prev_x;
    int prev_y;

    prev_x = data->prev_x;
    prev_y = data->prev_y;
    if ((data->map[next_x][next_y] == COINS) || (data->map[next_x][next_y] == BG))
    {
        if (data->map[next_x][next_y] == COINS)
            data->coins_count--;
        data->map[prev_x][prev_y] = BG;
        data->player_x = next_x;
        data->player_y = next_y;
        data->map[next_x][next_y] = PLAYER;
        map_draw(data);
    }
    if (data->map[next_x][next_y] == WALL)
    {
        data->player_x = prev_x;
        data->player_y = prev_y;
    }
    if (data->map[next_x][next_y] == EXIT)
    {
        if (data->coins_count == 0)
            exit_game(data);
        printf("%d coins missing !!\n", data->coins_count);
        data->player_x = prev_x;
        data->player_y = prev_y;
        
    }
    printf("%d\n", data->coins_count);
}

int handle_key(int keycode, t_data *data)
{
    data->prev_x = data->player_x;
    data->prev_y = data->player_y;
    if (keycode == XK_Escape)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }
    else if (keycode == XK_Up)
    {
        player_move(data, data->player_y, data->player_x -= 1);
    }
    else if (keycode == XK_Down)
            player_move(data, data->player_y, data->player_x += 1);
    else if (keycode == XK_Left)
            player_move(data, data->player_y -= 1, data->player_x);
    else if (keycode == XK_Right)
            player_move(data, data->player_y += 1, data->player_x);
    return (0);
}
