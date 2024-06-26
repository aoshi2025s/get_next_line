/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:15:18 by yoaoki            #+#    #+#             */
/*   Updated: 2024/06/26 23:04:31 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_getc(int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*buffptr;
	static int	read_byte;

	if (read_byte == 0)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte < 0)
			return (read_byte++, READ_ERROR);
		buffptr = buf;
	}
	read_byte--;
	if (read_byte >= 0)
		return (*buffptr++);
	return (read_byte++, EOF);
}

int	ft_putc(t_line *line, char c)
{
	char			*new_str;
	unsigned char	*dest;
	unsigned char	*src;
	size_t			len;

	if (line->len + 1 >= line->capacity)
	{
		line->capacity = (line->len + 1) * 2;
		new_str = (char *)malloc(sizeof(char) * line->capacity);
		if (!new_str)
			return (0);
		dest = (unsigned char *)new_str;
		src = (unsigned char *)line->str;
		len = line->len;
		while (len--)
			*dest++ = *src++;
		free(line->str);
		line->str = new_str;
	}
	line->str[line->len++] = c;
	return (1);
}

char	*get_next_line(int fd)
{
	t_line	line;
	char	c;

	if (fd < 0)
		return (NULL);
	line.str = 0;
	line.len = 0;
	line.capacity = 0;
	while (1)
	{
		c = ft_getc(fd);
		if (c == READ_ERROR)
			return (free(line.str), NULL);
		if (c == EOF)
			break ;
		if (ft_putc(&line, c) == 0)
			return (free(line.str), NULL);
		if (c == '\n')
			break ;
	}
	if (line.len > 0 && (ft_putc(&line, '\0') == 0))
		return (free(line.str), NULL);
	return (line.str);
}
