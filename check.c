#include "so_long.h"

int is_map_rectangular(char **map)
{
    int i;
    size_t len;

    i = 0;
    len = ft_strlen(map[0]);
    while (map[i])
    {
        if (ft_strlen(map[i]) != len)
        {
            printf("Error !! Map is not rectangular\n");
            return (0);
        }
        i++;
    }
    return (1);
}

int is_wall(char **map)
{
    int i;
    int j;
    size_t len;

    i = 0;
    j = 0;
    while (map[i] != NULL)
        i++;
    while (map[0][j] != '\0' && map[i - 1][j] != '\0')
    {
        if (map [0][j] != '1' || map[i - 1][j] != '1')
        {
            printf("Error, no wall !");
            return (0);
        }
        ++j; 
    }
    i = 1;
    len = ft_strlen(map[i]);
    while (map[i] != NULL)
    {
        if (map [i][0] != '1' || map[i][len - 1] != '1')
        {
            printf("Error, no wall2 !");
            return (0);
        }
        i++;
    }
    return (1);
}

int    *check_errors(t_data *data)
{
    is_map_rectangular(data->map);
    is_wall(data->map);
    //is_all_p(data->map);
    return (0);
}