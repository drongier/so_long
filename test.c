#include "so_long.h"

int main(int argc, char **argv)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 300, 300, "so_long :)");
	if (!data.win_ptr)
		return (1);
	mlx_loop(data.mlx_ptr);
	
	return (0);
}