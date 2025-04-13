/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabboudi <iabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:35:59 by sisser            #+#    #+#             */
/*   Updated: 2025/04/13 20:53:05 by iabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_game(t_data **data)
{
        (*data) = malloc(sizeof(t_data));
        if (!(*data))
                return (0);
	(*data)->north_texture = NULL;
        (*data)->south_texture = NULL;
        (*data)->east_texture = NULL;
        (*data)->west_texture = NULL;
        (*data)->floor_color = -1;
        (*data)->ceiling_color = -1;
	(*data)->map2d = malloc(sizeof(t_map2D));
        if (!((*data)->map2d))
	{
		free(*data);
		return (0);
	}
        (*data)->map2d->map = NULL;
        (*data)->map2d->width = 0;
        (*data)->map2d->height = 0;
        return (1);
}
