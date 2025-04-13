/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabboudi <iabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:38:25 by sisser            #+#    #+#             */
/*   Updated: 2025/04/13 20:54:43 by iabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int  get_map_height(char *line)
{
        size_t  i;
        size_t  height;

        i = 0;
        height = 0;
        while (line[i])
        {
                if (line[i] == '\n')
                        height++;
                i++;
        }
        return (height);
}

int  get_map_width(char *line)
{
        int	i;
        size_t  current_width;
        size_t  max_width;

        i = 0;
        current_width = 0;
        max_width = 0;
        while (line[i])
        {
                if (line[i] == '\n')
                {
                        if (current_width > max_width)
                                max_width = current_width;
                        current_width = 0;
                }
                else
                        current_width++;
                i++;
        }
        return (max_width);
}

char    **alloc_map(char *map_line)
{
        char    **map;
        int  height;
        int  width;
        int  i;

        height = get_map_height(map_line);
        width = get_map_width(map_line);
        map = malloc(sizeof(char *) * (height + 1));
        if (!map)
                return (NULL);
        i = 0;
        while (i < height)
        {
                map[i] = malloc(sizeof(char) * (width + 1));
                if (!map[i])
                {
                        while (i--)
                                free(map[i]);
                        return (free(map), NULL);
                }
                ft_memset(map[i], ' ', width);
                map[i++][width] = 0;
        }
        map[i] = NULL;
        return (map);
}

char    **parse_map_line(char *map_line)
{
        char    **map;
        int 	i;
        int  p_cur;
        int  y_cur;

        i = 0;
        p_cur = 0;
        y_cur = 0;
        map = alloc_map(map_line);
        if (!map)
                return (NULL);
        while (map_line[i])
        {
                if (map_line[i] == '\n')
                {
                        ft_strlcpy2(map[y_cur++], map_line + p_cur, i - p_cur + 1);
                        p_cur = i + 1;
                }
                i++;
        }
        return (map);
}
