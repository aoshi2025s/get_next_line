/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:30:51 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/07 16:59:31 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h> //OPEN_MAX 10240
# include <stdlib.h>
# include <unistd.h>

# ifndef EOF
#  define EOF 0x1A
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# if BUFFER_SIZE > 99999999 || BUFFER_SIZE <= 0
#  error "BUFFER_SIZE must be greater than 0 and less than or equal to 99999999"
# endif

# define READ_ERROR -42

typedef struct s_line
{
	char	*str;
	size_t	len;
	size_t	capacity;
}			t_line;

typedef struct s_buffinfo
{
	char	buf[BUFFER_SIZE];
	char	*buffptr;
	int		read_byte;
	int		prev_fd;
}			t_buffinfo;

char		*get_next_line(int fd);
char		*ft_strcpy(char *dest, const char *src);
char		ft_getchar(int fd);

int			ft_addchar(t_line *str, char c);

#endif
