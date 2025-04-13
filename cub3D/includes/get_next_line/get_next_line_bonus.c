/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:06:17 by sisser            #+#    #+#             */
/*   Updated: 2024/04/25 22:20:55 by sisser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*s[__FD_SETSIZE];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX
		|| fd > __FD_SETSIZE)
		return (NULL);
	s[fd] = read_line(fd, s[fd]);
	if (!s[fd])
		return (NULL);
	if (s[fd][0] == '\0')
	{
		free(s[fd]);
		s[fd] = 0;
		return (NULL);
	}
	line = extract_line(s[fd]);
	s[fd] = get_rest(s[fd]);
	return (line);
}
