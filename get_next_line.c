#include "get_next_line.h"

static int		rec_line(char *str, int fd, char **line, int res)
{
	char		t_ptr;
	int			i;

	i = 0;
	while (str[i] != '\n' || str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		if (res == BUFF_SIZE)
			return (fd_text(fd, line));
		*line = ft_strdup(str);
		ft_strdel(&str);
	}
	else if (str[i] == '\n')
	{
		*line = ft_strsub(str, 0, i);
		t_ptr = ft_strdup(str + i + 1);
		free(str);
		str = t_ptr;
		if (str[0] == '\0')
			ft_strdel(&str);
	}
	return (1);
}

static int		fd_text(int fd, char **line)
{
	static char		str[FD_MAX];
	int				res;
	char			piece[BUFF_SIZE];
	char			*t_ptr;

	res = 0;
	while ((res = read(fd, piece, BUFF_SIZE)))
	{
		if (res < 0)
			return (-1);
		piece[res] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(1);
		t_ptr = ft_strjoin(&str[fd], piece);
		free(str[fd]);
		*str[fd] = t_ptr;
		if (ft_strchr(piece, '\n'))
			break;
	}
	if ((str[fd] == NULL /*|| str[fd][0] = '\0'*/) && res == 0)
		return (0);
	else
		return (rec_line(&str[fd], fd, line, res));
}

int		get_next_line(const int fd, char **line)
{
	if (!fd || !line || fd > FD_MAX)
		return (-1);
	return(fd_text(fd, line));
}