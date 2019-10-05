
#include "get_next_line.h"

static int				ft_strsymcpy(char *buff, char *line)
{
	char				*endofline;
	size_t				i;
	
	i = 0;
	*endofline = *buff;
	while (endofline[i] != '\n')
		i++;
	line = ft_strnew(i);
	line[i] = '\0';
	while (i--)
		line[i] = buff[i];
	return (1);
}

int						get_next_line(const int fd, char **line) 
{
	static char			*buff[BUFF_SIZE];
	char				*str;
	int					res;
	int					i;

	i = 0;
	if (fd < 0 || fd > FD_MAX || !line || (res = read(fd, buff[fd], BUFF_SIZE) <= 0))
		return (-1);
	ft_strsymcpy(*buff, *line);
	return (0);
}

int				main(int argc, char **argv)
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);
	free(line);
	return (0);
}