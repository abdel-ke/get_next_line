/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:11:54 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/29 17:45:13 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	char		c3;
	char		*str;
	int			i;

	c3 = (char)c;
	str = (char *)s;
	i = 0;
	if (c3 == '\0')
		return (str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == c3)
			return (str + i);
		i++;
	}
	return (NULL);
}

char			*str_get(char *rest, int i, char **line)
{
	char		*ptr;

	while (rest[i])
	{
		if (rest[i] == '\n')
		{
			free(*line);
			*line = ft_substr(rest, 0, i);
			ptr = rest;
			rest = ft_strdup(rest + i + 1);
			free(ptr);
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
	static char	*str[4864];
	int			r;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 4864 || !line ||
	!(buff = (char *)malloc((sizeof(char)) * BUFFER_SIZE + 1)))
		return (-1);
	if (str[fd] == NULL)
		if (!(str[fd] = ft_calloc(1, 1)))
			return (-1);
	while ((!ft_chr(str[fd], '\n')) && (r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		temp = str[fd];
		str[fd] = ft_strjoin(str[fd], buff);
		free(temp);
	}
	free(buff);
	if (r < 0)
		free(str[fd]);
	if (r < 0)
		return (-1);
	*line = ft_strdup("");
	return (((str[fd] = str_get(str[fd], 0, line)) == NULL) ? 0 : 1);
}
