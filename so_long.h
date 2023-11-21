#ifndef SO_LONG_H
# define SO_LONG_H

#define SPRITE_WIDTH    32
#define SPRITE_HEIGHT   32
# define WALL				'1'
# define BG 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define EXIT 		 	    'E'

#include "libraries/libft/libft.h"
#include "libraries/minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <fcntl.h>
#include <string.h>
#define MLX_ERROR 1

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
    
    int fd;
    int win_width;
    int win_height;
    int img_width;
    int img_height;
    int player_x;
    int player_y;
    int prev_x;
    int prev_y;
    int player_count;
    int coins_count;
    int exit_count;

    void *spr_wall;
    void *spr_coin;
    void *spr_perso;
    void *spr_exit;
    void *spr_bg;


    char **map;
    char *buffer;
    char *buffer_map;



} t_data;

char    **read_map(t_data *data, char **argv);
int    *check_errors(t_data *data);
void init_map(t_data *data);
int	map_draw(t_data *data);
int handle_key(int keycode, t_data *data);
void	img_draw(t_data *data, void *image, int x, int y);
void exit_game(t_data *data);

#endif


