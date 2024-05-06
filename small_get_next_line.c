
/* getchar */
//#include <limits.h>
//#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
//# define EOF 0x1A

typedef struct s_string
{
	char *str;
	size_t len;
	size_t capa;
} t_string;

char	*ft_strcpy(char *dest, char *src)
{
	char *result;
	
	result = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (result);
}

// fdからreadで、BUFSIZ分の文字を読み込む
// read_byteが0以上の時は、bufに格納されてる文字を一つずつ横にずらして取得していく
// --read_byte
// read_byteが0になった時、bufに格納されてる文字は全部読めたので、新たにBUFSIZ分読み込む
// read_byteがマイナスになった時、ファイルの終わりってことなので、ファイル終端を表すEOFを返す
char	ft_getc(int fd)
{
	static char buf[BUFFER_SIZE];
	static char *bufptr;
	static int read_byte = 0;

	if (read_byte == 0)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		bufptr = buf;
	}
	read_byte--;
	if (read_byte >= 0)
		return ((unsigned char)*bufptr++);
	else
		return (EOF);
}

#include <string.h>

int	ft_putc(t_string *str, char c)
{
	t_string new_str;
	
	//printf("putc called\n");

	new_str.str = 0;
	if (str->len + 1 >= str->capa)
	{
		//printf("if bun no naka\n");
		//領域が足りなくなったら新たに確保して、コピー
		new_str.str = (char *)malloc(sizeof(char) * ((str->len + 1) * 2));
		// malloc faile -> should error handle
		//if(new_str.str)
			//printf("malloc success!\n");
		if (str->str)
			ft_strcpy(new_str.str, str->str);
	//	printf("new_str.str: %s\n", new_str.str);
		char *delete_str = str->str;
		str->str = new_str.str; 
		// should free
		str->capa = (str->len + 1) * 2;
	}
	//printf("if bun no soto\n");
	str->str[str->len] = c;
	str->len++;
	return (0);
}

char	*get_next_line(int fd)
{
	t_string	str;
	char		c;

	str.str = NULL;
	str.len = 0;
	str.capa = 0;


	while (1)
	{
		c = ft_getc(fd);
	//	printf("c: %c\n", c);
		if (c == EOF)
			break;
		ft_putc(&str, c);
		if (c == '\n')
			break;
	}
	if (str.len > 0)
		ft_putc(&str, '\0');
	return (str.str);
}
