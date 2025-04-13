/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:36:58 by sisser            #+#    #+#             */
/*   Updated: 2025/04/10 08:37:00 by sisser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int skip_spaces(char *line, int i)
{
    // Avance l'index tant que le caractère est un espace
    while (line[i] == ' ')
    {
        i++;
    }
    return i;  // Retourne l'index après les espaces
}

int     line_value_size(char *line, int i)
{
        int  size;

        size = 0;
        while (line[i + size] != '\n')
        {
                size++;
                if (ft_is_only(line + i + size, ' ') && line[i + size + 1] != '\n')
                        return (size);
        }
        return (size);
}

char    *get_line_value(int prefix_len, char *line)
{
        int i;

        i = skip_spaces(line, prefix_len);
        return (ft_substr(line, i, line_value_size(line, i)));
}
