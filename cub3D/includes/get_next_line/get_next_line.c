/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:08:18 by sisser            #+#    #+#             */
/*   Updated: 2024/04/25 17:44:11 by sisser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *s)
{
	int		nb;
	char	*buffer;

	buffer = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	nb = 1;
	while (!ft_strchr(s, '\n') && nb != 0)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb == -1)
		{
			free(buffer);
			buffer = 0;
			if (s)
				free(s);
			return (0);
		}
		buffer[nb] = '\0';
		s = ft_strjoin(s, buffer);
	}
	free(buffer);
	return (s);
}

char	*extract_line(char *s)
{
	int		n;
	char	*ligne;

	n = 0;
	while (s[n] != '\n' && s[n] != '\0')
		n++;
	if (s[n] == '\n')
		n++;
	ligne = (char *)malloc((n + 1) * sizeof(char));
	if (!ligne)
		return (NULL);
	n = 0;
	while (s[n] != '\n' && s[n] != '\0')
	{
		ligne[n] = s[n];
		n++;
	}
	if (s[n] == '\n')
		ligne[n++] = '\n';
	ligne[n] = '\0';
	return (ligne);
}

char	*get_rest(char *s)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		i++;
	rest = (char *)malloc((ft_strlen(s) - i + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	j = 0;
	while (s[i] != '\0')
	{
		rest[j] = s[i];
		i++;
		j++;
	}
	rest[j] = '\0';
	free(s);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	s = read_line(fd, s);
	if (!s)
		return (NULL);
	if (s[0] == '\0')
	{
		free(s);
		s = 0;
		return (NULL);
	}
	line = extract_line(s);
	s = get_rest(s);
	return (line);
}
