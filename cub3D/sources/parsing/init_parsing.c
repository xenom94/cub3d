/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:37:36 by sisser            #+#    #+#             */
/*   Updated: 2025/04/10 08:37:38 by sisser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*parse_file_map(char *file_path, t_data *data)
{
        int	map_fd;
        char	*line;
        char	*map_line;

        map_fd = open(file_path, O_RDONLY);
        if (map_fd < 0)
                return (free_parsed(data),
                        ft_putstr_fd("Error\n(Unable to open the map file)\n", 2), NULL);
        if (!check_map_extension(file_path))
                return (free_parsed(data),
                        print_error("Error\nThe map file extension is not .cub\n"));
        line = get_next_line(map_fd);
        if (!extract_map_values(map_fd, &line, data))
                return (NULL);
        map_line = get_map_content(map_fd, &line, data);
        if (!map_line)
                return (NULL);
        if (!has_every_data(data))
                return (free(map_line), free_parsed(data),
                        print_error("Error\n(The map does not contain all the textures and"
                                " colors information)\n"));
        if (ft_strlen(map_line) == 0)
                return (free(map_line), free_parsed(data),
                        print_error("Error\n(The content of the map is empty)\n"));
        return (map_line);
}

t_data	*setup_game(char *file_path)
{
        t_data	*data;
        char	*map_line;

        if (!init_data(&data))
                return (NULL);
        map_line = parse_file_map(file_path, data);
        if (!map_line)
                return (NULL);
        data->map2d->map = parse_map_line(map_line);
        if (!data->map2d->map)
                return (free(map_line), free(data), NULL);
        data->map2d->height = get_map_height(data->map2d->map);
        data->map2d->width = get_map_width(data->map2d->map);
        free(map_line);
        if (!check_map(data))
                return (free_parsed(data));
        get_player(data->map2d->map, &(data->player));
        return (data);
}


