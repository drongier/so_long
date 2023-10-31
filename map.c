#include "so_long.h"

void	print_map(char **map)
{
    int	i;

    i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
}

char    **read_map(t_data *data, char **argv)
{
    char    *read;

    data->fd = open(argv[1], O_RDONLY);
    if (data->fd < 0)
    {
        printf("Error !! Can't open map file\n");
        return (0);
    }
    data->buffer_map = ft_strdup("");
    while (1)
    {
        read = get_next_line(data->fd);
        if (!read)
            break;
        data->buffer = data->buffer_map;
        data->buffer_map = ft_strjoin(data->buffer, read);
        free(read);
        free(data->buffer);
    }
    data->map = ft_split(data->buffer_map, '\n');
    print_map(data->map);
    free(data->buffer_map);
    close(data->fd);
    return (data->map);
}