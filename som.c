
#include "get_next_line.h"

static t_list			*get_correct_file(t_list **file, int fd)
{
	t_list				*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

int						get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	static t_list		*file;
	int					i;
	int					ret;
	t_list				*curr;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	curr = get_correct_file(&file, fd);
	MALLCHECK((*line = ft_strnew(1)));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		MALLCHECK((curr->content = ft_strjoin(curr->content, buf)));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(curr->content))
		return (0);
	i = ft_copyuntil(line, curr->content, '\n');
	(i < (int)ft_strlen(curr->content))
		? curr->content += (i + 1)
		: ft_strclr(curr->content);
	return (1);
}




#include "get_next_line.h"

static int	ft_checkerror(int fd, char **line, char **str)
{
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || fd >= OPEN_MAX)
		return (-1);
	if (!str[fd])
		if (!(str[fd] = ft_strnew(0)))
			return (-1);
	return (0);
}

static int	ft_readline(const int fd, char **str)
{
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	if ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (!(tmp = ft_strdup(*str)))
			return (-1);
		ft_strdel(str);
		if (!(*str = ft_strjoin(tmp, buffer)))
			return (-1);
		ft_strdel(&tmp);
	}
	return (ret);
}

static int	ft_nextline(char **str, char *line_feed)
{
	char	*tmp;

	if (!(tmp = ft_strdup(line_feed + 1)))
		return (-1);
	ft_strdel(str);
	if (!(*str = ft_strdup(tmp)))
		return (-1);
	ft_strdel(&tmp);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		*line_feed;
	int			ret;

	if (ft_checkerror(fd, line, str) == -1)
		return (-1);
	while (!(line_feed = ft_strchr(str[fd], '\n')))
	{
		if ((ret = ft_readline(fd, &str[fd])) < 0)
			return (-1);
		if (ret == 0 && !line_feed)
		{
			if (str[fd][0] == '\0')
				return (0);
			if (!(*line = ft_strdup(str[fd])))
				return (-1);
			str[fd][0] = '\0';
			return (1);
		}
	}
	if (!(*line = ft_strsub(str[fd], 0, line_feed - str[fd])))
		return (-1);
	if (ft_nextline(&str[fd], line_feed) == -1)
		return (-1);
	return (1);
}
