#include "so_long.h"

int read_map(t_data *data, char **argv)
{
    data->fd = open(argv[1], O_RDONLY);
    if (data->fd < 0)
        return (0);
    

}