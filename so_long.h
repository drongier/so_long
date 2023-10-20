#ifndef SO_LONG_H
# define SO_LONG_H

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



} t_data;

int read_map(t_data *data, char **argv);


// cc so_long.c -lX11 -lXext -lmlx


