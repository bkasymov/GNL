/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:00:12 by dpenney           #+#    #+#             */
/*   Updated: 2019/09/27 22:40:57 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h> // УДАЛИТЬ!
# define BUFF_SIZE 4096 //Я выделил столько памяти, чтобы здесь сохранить всё содержимое открываемого файла
# define FD_MAX 256 //  Узнал через команду макс. значение дескриптора launchctl limit maxfiles
# define RET_VALUE(ret) ret > 0 ? 1 : ret

# include <fcntl.h> 
# include "./libft/libft.h"

int		get_next_line(const int fd, char **line); //определил как параметр для обращения.

#endif
