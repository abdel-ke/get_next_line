/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:13:03 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/29 17:43:40 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t			ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_chr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while (*str != (char)c && *str)
		str++;
	if (*str == (char)c)
		return (str);
	return (NULL);
}

char			*str_get(char *rest, int i, char **line)
{
	char		*temp;

	while (rest[i])
	{
		if (rest[i] == '\n')
		{
			free(*line);
			*line = ft_substr(rest, 0, i);
			temp = rest;
			rest = ft_strdup(rest + i + 1);
			free(temp);
			return (rest);
		}
		i++;
	}
	if (rest[0] != '\0')
	{
		free(*line);
		*line = ft_substr(rest, 0, i);
	}
	free(rest);
	return (NULL);
}

int				get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*str;
	int			r;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 4864 || !line
	|| !(buff = (char *)malloc((sizeof(char)) * BUFFER_SIZE + 1)))
		return (-1);
	if (str == NULL)
		if (!(str = ft_calloc(1, 1)))
			return (-1);
	while ((!ft_chr(str, '\n')) && (r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		temp = str;
		str = ft_strjoin(str, buff);
		free(temp);
	}
	free(buff);
	if (r < 0)
		free(str);
	if (r < 0)
		return (-1);
	*line = ft_strdup("");
	return (((str = str_get(str, 0, line)) == NULL) ? 0 : 1);
}
