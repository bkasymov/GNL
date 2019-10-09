#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
//	static char	str[FD_MAX];
	char		piece[BUFF_SIZE + 1];
	int			res;
	char		*j_ptr;
	
	res = 0;
	if (!fd || (res = read(fd, piece, BUFF_SIZE)) < 0 || fd > FD_MAX || !line)
		return (-1);
	res = 0;
	while ((res = read(fd, piece, BUFF_SIZE)) > 0)
	{
		piece[res] = '\0';
		*line = ft_strnew(1);
		j_ptr = ft_strjoin(*line, piece);
		free(*line);
		line = &j_ptr;
		if (ft_strchr(piece, '\n'))
			break;
	}
	return (0);
}