
#include "get_next_line.h"

static					ft_rec_line(int fd, char **str, char **line, int res)
{
	char		*tmp_ptr;
	int			i;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		tmp_ptr = ft_strdup(str[fd] + i);
		free(str[fd]);
		str[fd] = tmp_ptr;
		if (str[fd][0] == '\0')
			ft_strdel(str[fd]);
	}
	else if (str[fd][i] == '\0')
	{
		if (res == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(str[fd]);
	}
	return (1);
}

int						get_next_line(const int fd, char **line) 
{
	static	char		str[FD_MAX];
	int					res;
	char				buff[BUFF_SIZE];
	char				*tmp_ptr;

	res = 0;
	if (fd < 0 || fd > FD_MAX || !line) 
		return (-1);
	while (res = read(fd, buff, BUFF_SIZE) > 0)
	{
		buff[res] = '\0';
		if (str[fd]) == NULL)
			str[fd] = ft_strnew(1);
		tmp_ptr = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp_ptr;
		if (ft_strchr(buff, '\n'))
			break;
	}
	if (res < 0)
		return (-1);
	else if (res == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	ft_rec_line(fd, str, line, res)
	return (1);
}