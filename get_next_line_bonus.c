/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 06:19:06 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/15 00:58:17 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	ft_getchar(int fd)
{
	static t_buffinfo	buffinfo[OPEN_MAX + 1];

	if (buffinfo[fd].read_byte == 0)
	{
		buffinfo[fd].read_byte = read(fd, buffinfo[fd].buf, BUFFER_SIZE);
		if (buffinfo[fd].read_byte < 0)
			return (READ_ERROR);
		buffinfo[fd].buffptr = buffinfo[fd].buf;
	}
	buffinfo[fd].read_byte--;
	if (buffinfo[fd].read_byte >= 0)
		return (*(buffinfo[fd].buffptr)++);
	return (EOF);
}

int	ft_addchar(t_line *str, char c)
{
	char	*new_str;

	new_str = 0;
	if (str->len + 1 >= str->capacity)
	{
		str->capacity = (str->len + 1) * 2;
		new_str = (char *)malloc(sizeof(char) * str->capacity);
		if (new_str == NULL)
			return (0);
		ft_memcpy(new_str, str->str, str->len);
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
	str.str = NULL;
	str.len = 0;
	str.capacity = 0;
	while (1)
	{
		c = ft_getchar(fd);
		if (c == READ_ERROR)
			return (free(str.str), NULL);
		if (c == EOF)
			break ;
		if (ft_addchar(&str, c) == 0)
			return (free(str.str), NULL);
		if (c == '\n')
			break ;
	}
	if (str.len > 0 && (ft_addchar(&str, '\0') == 0))
		return (free(str.str), NULL);
	return (str.str);
}
