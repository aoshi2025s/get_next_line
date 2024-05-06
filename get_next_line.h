/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:15:55 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/07 06:02:21 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef EOF
#  define EOF 0x1A
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define READ_ERROR -42

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	capacity;
}			t_string;

char		*get_next_line(int fd);
char		*ft_strcpy(char *dest, const char *src);
char		ft_getchar(int fd);

int			ft_addchar(t_string *str, char c);

#endif
