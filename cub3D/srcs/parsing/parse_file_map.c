/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabboudi <iabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:37:24 by sisser            #+#    #+#             */
/*   Updated: 2025/04/13 20:54:39 by iabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int     extract_map_data(int map_fd, char **line, t_data *data)
{
        while (*line != NULL)
        {
                if (!ft_strncmp("NO", *line, 2) || !ft_strncmp("SO", *line, 2)
                        || !ft_strncmp("EA", *line, 2) || !ft_strncmp("WE", *line, 2))
                {
                        if (!extract_texture(*line, data))
                                return (free_data(data), free(*line),
                                        free(get_next_line(map_fd)), 0);
                }
                else if (!ft_strncmp("F", *line, 1) || !ft_strncmp("C", *line, 1))
                {
                        if (!extract_color(*line, data))
                                return (free_data(data), free(*line),
                                        free(get_next_line(map_fd)), 0);
                }
                else if (!ft_is_empty(*line))
                        return (1);
                free(*line);
                *line = get_next_line(map_fd);
        }
        return (1);
}


int     check_map_extension(char *file_path)
{
        int	length;

        length = ft_strlen(file_path);
        if (length < 4)
                return (0);
        else if (ft_strncmp(&file_path[length - 4], ".cub", 4))
                return (0);
        else
                return (1);
}

char    *parse_file_map(char *file_path, t_data *data)
{
        int     map_fd;
        char    *line;
        char    *map_line;

        map_fd = open(file_path, O_RDONLY);
        if (map_fd < 0)
                return (ft_putstr_fd("Error\n(Cannot open the file of this map)\n", 2), free_data(data));
        if (!check_map_extension(file_path))
                return (ft_putstr_fd("Error\n(The map file extension is not .cub)\n", 2), free_data(data));
        line = get_next_line(map_fd);
        if (!extract_map_data(map_fd, &line, data))
                return (NULL);
        map_line = get_map_content(map_fd, &line, data);
        if (!map_line)
                return (NULL);
        if (!has_every_data(data))
                return (free(map_line), free_data(data),
                        ft_putstr_fd("Error\n(The map does not contain all informations)\n", 2),NULL);
        if (ft_strlen(map_line) == 0)
                return (free(map_line), free_data(data),
                        ft_putstr_fd("Error\n(The content of the map is empty)\n",2), NULL);
        return (map_line);
}
