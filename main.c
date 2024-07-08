/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:45:29 by yoaoki            #+#    #+#             */
/*   Updated: 2024/07/08 14:02:09 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> // open
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // close

char	*get_next_line(int fd);

/*
__attribute__((destructor)) static void destructor()
{
	system("leaks -q a.out");
}
*/

int	main(int argc, char **argv)
{
	char	*pathname;
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("please input file path\n");
		return (0);
	}
	pathname = argv[1];
	fd = open(pathname, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
