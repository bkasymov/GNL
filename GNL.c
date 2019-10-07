
#include "get_next_line.h"

static int						ft_remain(char *rem, char **line)
{
	char						*ptr_nx;

	ptr_nx = NULL;
	if (rem)
	{
		if (ptr_nx = ft_strchr(rem, '\n'))
		{
			*ptr_nx = '\0'
			*line = ft_strdup(rem);
			ptr_nx++;
			ft_strcpy(rem, ptr_nx);
		}
		else
		{
			*line = ft_strdup(rem);
			ft_strclr(rem);
		}
	}
	else
	{
		*line = ft_strnew(1);
	}
	return (ptr_nx);
}

int						ft_read(int fd, char **line)
{

	static char			rem;
	char				buff[BUFF_SIZE];
	int					endtx;

	while (!ptr_nx && (endtx = read(fd, buff, BUFF_SIZE))) 
	{
		buff[endtx] = '\0';
		if (ptr_nx = ft_strchr(buff, '\n'))
		{
			*ptr_nx = '\0';
			ptr_nx++;
			rem = ft_strdup(ptr_nx);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
	}
	return ;
}

int						get_next_line(const int fd, char **line) 
{
	char				*ptr_nx;

	res = 1;
	if (fd < 0 || fd > FD_MAX || !line) 
		return (-1);
	ptr_nx = ft_remain(rem, line)
	ft_read(fd, line)
	
	return (0);
}

int				main(int argc, char **argv)
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);
	return (0);
}
