/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:15:18 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/07 02:01:13 by yoaoki           ###   ########.fr       */
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
		buffptr = buf;
	}
	read_byte--;
	if (read_byte >= 0)
		return ((unsigned char)*buffptr++);
	else
		return (EOF);
}

int	ft_addchar(t_string *str, char c)
{
	t_string	new_str;
	char		*delete_str;

	new_str.str = 0;
	if (str->len + 1 >= str->capacity)
	{
		new_str.str = (char *)malloc(sizeof(char) * ((str->len + 1) * 2));
		if (!new_str.str)
		{
			if (str->str)
				free(str->str);
			return (0);
		}
		if (str->str != NULL)
			ft_strcpy(new_str.str, str->str);
		delete_str = str->str;
		str->str = new_str.str;
		free(delete_str);
		str->capacity = (str->len + 1) * 2;
	}
	str->str[str->len] = c;
	str->len++;
	return (1);
}

char	*get_next_line(int fd)
{
	t_string	str;
	char		c;

	str.str = NULL;
	str.len = 0;
	str.capacity = 0;
	while (1)
	{
		c = ft_getchar(fd);
		if (c == EOF)
			break ;
		ft_addchar(&str, c);
		if (c == '\n')
			break ;
	}
	if (str.len > 0)
		ft_addchar(&str, '\0');
	return (str.str);
}






