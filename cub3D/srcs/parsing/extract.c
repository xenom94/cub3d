/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabboudi <iabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:36:45 by sisser            #+#    #+#             */
/*   Updated: 2025/04/13 20:54:22 by iabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char    *extract_texture(char *line, t_data *map)
{
        char	**texture;
        int	fd;

        texture = NULL;
        if (!ft_strncmp("NO", line, 2))
                texture = &(map->north_texture);
        if (!ft_strncmp("SO", line, 2))
                texture = &(map->south_texture);
        if (!ft_strncmp("EA", line, 2))
                texture = &(map->east_texture);
        if (!ft_strncmp("WE", line, 2))
                texture = &(map->west_texture);
        if (texture)
        {
                if (*texture != NULL)
                        return (ft_putstr_fd("Error\n(You can't set a texture more than once)\n", 2),NULL);
                *texture = get_line_value(2, line);
                if (!*texture)
                        return (0);
                fd = open(*texture, O_RDONLY);
                if (fd < 0)
                        return (ft_putstr_fd("Error\n(Unable to open texture file)\n", 2),NULL);
        }
        return (*texture);
}

int     find_chr(char *str, char c)
{
        int     i;

        i = 0;
        while (str[i] != 0)
        {
                if (str[i] == c)
                        return (i);
                i++;
        }
        return (-1);
}

void    *extract_color(char *line, t_data *map)
{
        char    *color;
        int             *color_num;
        int             i;

        color_num = NULL;
        if (!ft_strncmp("C", line, 1))
                color_num = &(map->ceiling_color);
        else if (!ft_strncmp("F", line, 1))
                color_num = &(map->floor_color);
        else
                return (NULL);
        if (*color_num != -1)
                return (ft_putstr_fd("Error\n(You can't set a color more than once)\n", 2), NULL);
        color = rgb_to_hex(get_line_value(2, line));
        if (!color)
                return (NULL);
        i = 0;
        *color_num = 0;
        while (color[i])
                *color_num = *color_num * 16
                        + find_chr("0123456789ABCDEF", color[i++]);
        free(color);
        return ((void *)1);
}
