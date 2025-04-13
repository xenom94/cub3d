/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabboudi <iabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:38:56 by sisser            #+#    #+#             */
/*   Updated: 2025/04/13 20:54:50 by iabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int     check_map_line(char *line)
{
        int  i;

        i = 0;
        while (line[i] && line[i] != '\n')
        {
                if (!ft_str_contains(" 10NSEWP", line[i]))
                        return (0);
                i++;
        }
        return (1);
}

int     map_content_valid(char *line)
{
        if (!check_map_line(line))
        {
                ft_putstr_fd("Error\n(The map content contains invalid characters)\n", 2);
                return (0);
        }
        else if (ft_is_empty(line))
        {
                ft_putstr_fd("Error\n(The map content contains empty lines)\n", 2);
                return (0);
        }
        else if (ft_is_only(line, ' '))
        {
                ft_putstr_fd("Error\n(The map content contains lines with only spaces)\n", 2);
                return (0);
        }
        else
                return (1);
}

int     valid_data(t_data *map)
{
        int	count;

        count = 0;
        if (map->north_texture)
                count++;
        if (map->south_texture)
                count++;
        if (map->east_texture)
                count++;
        if (map->west_texture)
                count++;
        if (map->floor_color != -1)
                count++;
        if (map->ceiling_color != -1)
                count++;
        if (count == 6)
                return (1);
        return (0);
}

char    *get_map_content(int map_fd, char **line, t_data *data)
{
        char    *map_line;

        map_line = ft_strdup("");
        while (*line != NULL)
        {
                if (!valid_data(data))
                {
                        ft_putstr_fd("Error\n(The map does not contain all data)\n" ,2);
                        return (free_parsing_el(data, &map_line, line, map_fd));
                }
                else if (!is_map_content_valid(*line))
                        return (free_parsing_el(data, &map_line, line, map_fd));
                else
                {
                        map_line = ft_strappend(&map_line, *line);
                        if (!map_line)
                                return (free_parsed(data), free(*line),
                                        free(get_next_line(map_fd)), NULL);
                }
                free(*line);
                *line = get_next_line(map_fd);
        }
        return (map_line);
}
