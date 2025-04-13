/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:38:34 by sisser            #+#    #+#             */
/*   Updated: 2025/04/10 08:38:36 by sisser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char    *decimal_to_hexadecimal(int decimal)
{
        char    *hexadecimal;
        int             i;

        if (decimal < 0 || decimal > 255)
                return (NULL);
        hexadecimal = ft_calloc(3, sizeof(char));
        if (!hexadecimal)
                return (NULL);
        ft_memset(hexadecimal, '0', 2);
        i = 1;
        while (decimal > 0)
        {
                hexadecimal[i--] = "0123456789ABCDEF"[decimal % 16];
                decimal /= 16;
        }
        return (hexadecimal);
}

int     check_rgb_string_format(char *rgb_string)
{
        int     i;
        int     comma_count;

        i = 0;
        comma_count = 0;
        while (rgb_string[i])
        {
                if (rgb_string[i] == ',')
                {
                        comma_count++;
                        if (comma_count > 2)
                                return (0);
                }
                else if (rgb_string[i] == '+')
                {
                        if (!ft_isdigit(rgb_string[i + 1]))
                                return (0);
                }
                else if (!ft_isdigit(rgb_string[i]))
                        return (0);
                i++;
        }
        return (1);
}

char    **rgb_string_to_array(char *rgb)
{
        char    **rgbs;

        if (!check_rgb_string_format(rgb))
        {
                free(rgb);
                ft_printf("Error\n(Invalid RGB color format)\n");
                return (NULL);
        }
        rgbs = ft_split(rgb, ',');
        return (rgbs);
}

char    *rgb_to_hex(char *rgb)
{
        char    *color;
        char    **rgbs;
        char    *temp_hex;
        int	i;

        color = ft_strdup("");
        rgbs = rgb_string_to_array(rgb);
        if (!rgbs)
                return (free(color), NULL);
        i = 0;
        while (rgbs[i])
        {
                if (ft_atoi(rgbs[i]) > 255 || ft_atoi(rgbs[i]) < 0)
                        return (free_rgb(rgb, rgbs), free(color),
                                ft_putstr_fd("Error\n(Color value must be between 0 and 255)\n", 2),NULL);
                temp_hex = decimal_to_hexadecimal(ft_atoi(rgbs[i++]));
                if (!temp_hex)
                        return (free_rgb(rgb, rgbs), free(color), NULL);
                color = ft_strappend(&color, temp_hex);
                if (!color)
                        return (free_rgb(rgb, rgbs), free(temp_hex), NULL);
                free(temp_hex);
        }
        return (free_rgb(rgb, rgbs), color);
}
