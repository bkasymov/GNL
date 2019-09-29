
#include "string.h"
# include <fcntl.h> 
# include "libft/libft.h"
# define BUFF_SIZE 4096 //Я выделил столько памяти, чтобы здесь сохранить всё содержимое открываемого файла
# define FD_MAX 256 //  Узнал через команду макс. значение дескриптора launchctl limit maxfiles
#include <stdio.h>

char			*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;

	i = 0;
	while (s1[i])
		i += 1;
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

/*
** Allocates with malloc() and returns a “fresh” string ending with ’\0’,
** result of the concatenation of s1 and s2. If the allocation fails the
** function returns NULL.
*/

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	char		*tmp_s3;
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	while (s1[i])
		i += 1;
	while (s2[j])
		j += 1;
	if (!s1 || !s2 || !(s3 = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	tmp_s3 = s3;
	while (*s1 != '\0')
		*tmp_s3++ = *s1++;
	while (*s2 != '\0')
		*tmp_s3++ = *s2++;
	*tmp_s3 = '\0';
	return (s3);
}

/*
** Verify if whatever is in the buff, has a newline. If it doesn't, returns
** a zero (0) to indicate that it's not valid. If there is a newline, we make a
** copy of the buff into the line, and we copied whatever was in the buff
** before, back to the buff (with the temporary buff that we created).
*/

int			gnl_verify_line(char **buff, char **line)
{
	char			*tmp_buff;
	char			*strchr_buff;
	int				i;

	i = 0;
	strchr_buff = *buff; 
	while (strchr_buff[i] != '\n') /*проверка присутствия символа новой 
									строки*/
		if (!strchr_buff[i++]) /*если не встретилась, то возврат нуля. */
			return (0);
	tmp_buff = &strchr_buff[i];
	*tmp_buff = '\0';
	*line = ft_strdup(*buff);
	*buff = ft_strdup(tmp_buff + 1);
	return (1);
}

/*
** Reads into the str, from the file descriptors, a specific number of bytes
** defined by the BUFF_SIZE macro in the get_nex_line.h file. It's going to
** continue the reading when the return value of the read function is greater
** than zero (no errors, or if there is nothing else to read).
** If there is something in the buff, we will concatinate whatever is in
** there, with whatever is read in the str. If no, we will just add
** whatever is in the str into the buff. Then we will verify the buff to
** see if there is a newline. If there is, we will break from the while loop
** and force the positive ret value into a one (1), using the RET_VALUE() macro.
** This answer form SO helped me visualize the buff and str in a better way:
** http://buffoverflow.com/a/1213360
*/

int			gnl_read_file(int fd, char *str, char **buff, char **line)
{
	int				ret;
	char			*tmp_buff;

	while ((ret = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[ret] = '\0';
		if (*buff)
		{
			tmp_buff = *buff;
			*buff = ft_strjoin(tmp_buff, str);
			free(tmp_buff);
			tmp_buff = NULL;
		}
		else
			*buff = ft_strdup(str);
		if (gnl_verify_line(buff, line))
			break ;
	}
	return (RET_VALUE(ret));
}

/*
** This is where the real shit happens.
** It first checks for errors (is the line is empty, if the number of the file
** descriptor is invalid, or if it fails to allocate the str), so it can return
** a minus one (-1) if needed.
**
** If there is something in the buff (because we are using a static variable),
** we verify that there is a newline. If not, we allocate memory for the str,
** and we read the file.
**
** When the reading of the file ends, we will free the str (we're not gonna
** use it anymore), and we check for the value of ret (if it's 1 or -1, return
** that, if the buff is empty, return 0). If neither of these conditions are
** valid, we assing line to the value of the buff, free the buff, and return 1
**
** A good read about file descriptors:
** http://www.bottomupcs.com/file_descriptors.xhtml
*/

int					get_next_line(int const fd, char **line)
{
	static char		*buff[FD_MAX];
	char			*str;
	int				ret;
	int				i;

	if (!line || (fd < 0 || fd >= FD_MAX) || (read(fd, buff[fd], 0) < 0) \
		|| !(str = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (buff[fd])
		if (gnl_verify_line(&buff[fd], line))
			return (1);
	i = 0;
	while (i < BUFF_SIZE)
		str[i++] = '\0';
	ret = gnl_read_file(fd, str, &buff[fd], line);
	free(str);
	if (ret != 0 || buff[fd] == NULL || buff[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = buff[fd];
	buff[fd] = NULL;
	return (1);
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