#include "so_long.h"

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
	// data.mlx_ptr = mlx_init();
	// if (!data.mlx_ptr)
	// 	return (1);
	// data.win_ptr = mlx_new_window(data.mlx_ptr, 300, 300, "hi :)");
	// if (!data.win_ptr)
	// 	return (1);
	// mlx_loop(data.mlx_ptr);
	
	return (0);
}