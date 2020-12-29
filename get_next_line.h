/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:13:04 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/29 18:02:13 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE -1
# endif

size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_calloc(size_t count, size_t size);
int			get_next_line(int fd, char **line);
char		*str_get(char *rest, int i, char **line);
void		ft_bzero(void *s, size_t n);
char		*ft_chr(const char *s, int c);

#endif
