#include "so_long.h"

int is_all_p(t_data *data)
{
    int i = 0;
    int j = 0;

    data->coins_count = 0;
    data->exit_count = 0;
    data->player_count = 0;

    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'P')
            {
                data->player_count++;
                data->player_x = i;
                data->player_y = j;
            }
            else if (data->map[i][j] == 'C')
                data->coins_count++;
            else if (data->map[i][j] == 'E')
                data->exit_count++;
            j++;
        }
        i++;
    }
    if (data->player_count != 1 || data->coins_count == 0 || data->exit_count != 1)
    {
        printf("Error with params !! ");
        return (0);
    }
    return (1);
}

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
            printf("Error, no wall !\n");
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
            printf("Error, no wall !\n");
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
    is_all_p(data);
    return (0);
}