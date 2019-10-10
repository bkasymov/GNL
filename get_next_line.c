#include "get_next_line.h"

static int		rec_line(char **str, int fd, char **line, int res)
{
	char		*t_ptr;
	int			i;

	i = 0;
	while (str[fd][i] != '\n' || str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		t_ptr = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = t_ptr;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else
	{
		if (res == BUFF_SIZE) // прочиталось ли всё проверяется через сравнение кол-во прочитанных и кол-во максимально выделенных. 
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

static int		fd_text(int fd, char **line)
{
	static char		*str[OPEN_MAX];
	int				res;
	char			piece[BUFF_SIZE];
	char			*t_ptr;

	res = 0;
	while ((res = read(fd, piece, BUFF_SIZE)) > 0)
	{
		if (res < 0)
			return (-1);
		piece[res] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(1);
		t_ptr = ft_strjoin(str[fd], piece);
		free(str[fd]);
		str[fd] = t_ptr;
		if (ft_strchr(piece, '\n'))
			break;
	}
	if ((str[fd] == NULL || str[fd][0] == '\0') && res == 0)
		return (0);
	return (rec_line(str, fd, line, res));
}

int		get_next_line(const int fd, char **line)
{
	if (!fd || !line || fd > OPEN_MAX)
		return (-1);
	return(fd_text(fd, line));
}