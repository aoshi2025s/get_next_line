#include <stdio.h>

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd);

int	main(void)
{
	printf("program start !\n");
	int	fd;
	char *result;
	fd = open("sample.txt", O_RDONLY);
	printf("file opened !\n");
	while(1)
	{
		result = get_next_line(fd);
		printf("%s", result);
		if (!result)
			break;
		free(result);
	}
	printf("program end !\n");
	return (0);
}

