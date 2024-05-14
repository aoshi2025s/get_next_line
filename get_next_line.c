/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:15:18 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/15 00:58:01 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_getchar(int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*buffptr;
	static int	read_byte;

	if (read_byte == 0)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte < 0)
			return (READ_ERROR);
		buffptr = buf;
	}
	read_byte--;
	if (read_byte >= 0)
		return (*buffptr++);
	return (EOF);
}

int	ft_addchar(t_line *line, char c)
{
	t_line	new_str;
	char	*delete_str;

	new_str.str = 0;
	if (line->len + 1 >= line->capacity)
	{
		new_str.str = (char *)malloc(sizeof(char) * ((line->len + 1) * 2));
		if (!new_str.str)
			return (0);
		if (line->str != NULL)
			ft_memcpy(new_str.str, line->str, line->len);
		delete_str = line->str;
		line->str = new_str.str;
		free(delete_str);
		line->capacity = (line->len + 1) * 2;
	}
	line->str[line->len] = c;
	line->len++;
	return (1);
}

char	*get_next_line(int fd)
{
	t_line	line;
	char	c;

	if (fd < 0)
		return (NULL);
	line.str = NULL;
	line.len = 0;
	line.capacity = 0;
	while (1)
	{
		c = ft_getchar(fd);
		if (c == READ_ERROR)
			return (free(line.str), NULL);
		if (c == EOF)
			break ;
		if (ft_addchar(&line, c) == 0 && line.str)
			return (free(line.str), NULL);
		if (c == '\n')
			break ;
	}
	if (line.len > 0 && (ft_addchar(&line, '\0') == 0))
		return (free(line.str), NULL);
	return (line.str);
}
