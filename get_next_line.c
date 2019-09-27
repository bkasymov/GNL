/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:08:27 by dpenney           #+#    #+#             */
/*   Updated: 2019/09/27 23:03:32 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(const int fd, char **line)
{
	int			buf[12000];
	char		*ln;
	int			rd;

	if (fd == 0 || line != NULL)
		return (-1);
	while ((rd = (read(fd, buff, BUFF_SIZE) > 0)
	{

	}

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
