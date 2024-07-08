/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 06:19:06 by yoaoki            #+#    #+#             */
/*   Updated: 2024/07/08 13:44:35 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	ft_getc(int fd)
{
	static t_buffinfo	buffinfo[OPEN_MAX + 1];

	if (buffinfo[fd].read_byte == 0)
	{
		buffinfo[fd].read_byte = read(fd, buffinfo[fd].buf, BUFFER_SIZE);
		if (buffinfo[fd].read_byte < 0)
			return (buffinfo[fd].read_byte++, READ_ERROR);
		buffinfo[fd].buffptr = buffinfo[fd].buf;
	}
	buffinfo[fd].read_byte--;
	if (buffinfo[fd].read_byte >= 0)
		return (*(buffinfo[fd].buffptr)++);
	return (buffinfo[fd].read_byte++, EOF);
}

int	ft_putc(t_line *str, char c)
{
	char	*new_str;
	char	*dest;
	char	*src;
	size_t	len;

	new_str = 0;
	if (str->len + 1 >= str->capa)
	{
		str->capa = (str->len + 1) * 2;
		new_str = (char *)malloc(sizeof(char) * str->capa);
		if (new_str == NULL)
			return (0);
		dest = new_str;
		src = str->str;
		len = str->len;
		while (len--)
			*dest++ = *src++;
		free(str->str);
		str->str = new_str;
	}
	str->str[str->len++] = c;
	return (1);
}

char	*get_next_line(int fd)
{
	t_line	str;
	char	c;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	str.str = 0;
	str.len = 0;
	str.capa = 0;
	while (1)
	{
		c = ft_getc(fd);
		if (c == READ_ERROR)
			return (free(str.str), NULL);
		if (c == EOF)
			break ;
		if (ft_putc(&str, c) == 0)
			return (free(str.str), NULL);
		if (c == '\n')
			break ;
	}
	if (str.len > 0 && (ft_putc(&str, '\0') == 0))
		return (free(str.str), NULL);
	return (str.str);
}
