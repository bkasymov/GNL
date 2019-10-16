/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:00:12 by dpenney           #+#    #+#             */
/*   Updated: 2019/10/15 03:09:28 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define BUFF_SIZE 16
# define FD_MAX 100000
# define BUFF_MAX 11000

int		get_next_line(const int fd, char **line);

#endif
