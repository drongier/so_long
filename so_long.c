#include "so_long.h"
#include "libraries/minilibx-linux/mlx.h"

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
	{
		printf("Error !! Try : a.out + map.ber\n");
		return (0);
	}
	read_map(&data, argv);
	check_errors(&data);
	init_map(&data);
	mlx_hook(data.win_ptr, 2, 1L<<0, &handle_key, &data);
	mlx_loop(data.mlx_ptr);
	mlx_loop_end(data.mlx_ptr);
	
	return (0);
}