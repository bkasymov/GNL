/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 03:09:49 by dpenney           #+#    #+#             */
/*   Updated: 2019/10/15 03:47:29 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	rec_line(int fd, char **line, char **rem)
{
	int		i;
	char	*t_ptr2;

	i = 0;
	while (rem[fd][i] != '\n' && rem[fd][i] != '\0')
		i++;
	if (rem[fd][i] == '\n')
	{
		*line = ft_strsub(rem[fd], 0, i);
		t_ptr2 = ft_strdup(rem[fd] + i + 1);
		free(rem[fd]);
		rem[fd] = t_ptr2;
		if (rem[fd][0] == '\0')
			ft_strdel(&rem[fd]);
	}
	else if (rem[fd][i] == '\0')
	{
		*line = ft_strdup(rem[fd]);
		ft_strdel(&rem[fd]);
	}
	return (1);
}

static int	give_line(int fd, char **line, char **rem, int rsr)
{
	char	*t_ptr;
	char	*buff;

	if (!(buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((rsr = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (rsr < 0)
			return (-1);
		buff[rsr] = '\0';
		if (rem[fd] == NULL)
			rem[fd] = ft_strnew(1);
		t_ptr = ft_strjoin(rem[fd], buff);
		free(rem[fd]);
		rem[fd] = t_ptr;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	if (rsr == 0 && (rem[fd][0] == '\0' || rem[fd] == NULL))
		return (0);
	return (rec_line(fd, line, rem));
}

int			get_next_line(int fd, char **line)
{
	static char	*rem[OPEN_MAX];
	int			rsr;

	rsr = 0;
	if (fd < 0 || line == NULL || fd > OPEN_MAX || \
								BUFF_SIZE <= 0)
		return (-1);
	return (give_line(fd, line, rem, rsr));
}










#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/*
**  1 line with 8 chars with Line Feed
*/

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "gnl1_1.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break;
		}
		close(fd);
		if (count_lines != 1)
			printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567\" instead of \"%s\"\n", line);
		if (count_lines == 1 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}
