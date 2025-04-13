/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabboudi <iabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:37:08 by sisser            #+#    #+#             */
/*   Updated: 2025/04/13 20:54:25 by iabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	free_map2d(t_map2D *map2d)
{
        int  i;

        i = 0;
        while (i < map2d->height)
                free(map2d->map[i++]);
        free(map2d->map);
        free(map2d);
        return (0);
}


void    *free_data(t_data *map)
{
        if (map->north_texture)
                free(map->north_texture);
        if (map->south_texture)
                free(map->south_texture);
        if (map->east_texture)
                free(map->east_texture);
        if (map->west_texture)
                free(map->west_texture);
        free_map2d(map->map2d);
        free(map);
        return (NULL);
}

void free_rgb(char *rgb_line, char **rgb)
{
    free(rgb_line);
    free(rgb[0]);
    free(rgb[1]);
    free(rgb[2]);
    free(rgb);
}
