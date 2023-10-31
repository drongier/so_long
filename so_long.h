#ifndef SO_LONG_H
# define SO_LONG_H

#include "libraries/libft/libft.h"
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
    int width;
    int height;
    int player_x;
    int player_y;

    char **map;
    char *buffer;
    char *buffer_map;



} t_data;

char    **read_map(t_data *data, char **argv);
int    *check_errors(t_data *data);

#endif
// cc so_long.c -lX11 -lXext -lmlx


