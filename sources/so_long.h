/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:55:32 by drongier          #+#    #+#             */
/*   Updated: 2023/11/28 14:25:51 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <string.h>
# include "../libraries/libft/libft.h"
# include "../libraries/ft_printf/ft_printf.h"
# include "../libraries/minilibx-linux/mlx.h"

# define SPRITE_WIDTH	32
# define SPRITE_HEIGHT	32
# define MLX_ERROR	1

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr; 
	int		fd;
	int		win_width;
	int		win_height;
	int		img_width;
	int		img_height;
	int		player_x;
	int		player_y;
	int		prev_x;
	int		prev_y;
	int		player_count;
	int		coins_count;
	int		exit_count;
	int		move_count;
	void	*spr_wall;
	void	*spr_coin;
	void	*spr_perso;
	void	*spr_exit;
	void	*spr_bg;
	char	**map;
	char	*buffer;
	char	*buffer_map;

}	t_data;

char	**read_map(t_data *data, char **argv);
int		*check_errors(t_data *data);
void	init_map(t_data *data);
int		map_draw(t_data *data);
int		handle_key(int keycode, t_data *data);
void	img_draw(t_data *data, void *image, int x, int y);
void	exit_game(t_data *data);
int		close_window(void *param);
int		ft_printf(const char *str, ...);
int		print_error(int i);

#endif
