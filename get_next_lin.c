
#include "get_next_line.h"

int		ft_new_line(char **s, char **line, int fd, int text)
{
	char	*temp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')//считаем кол-во строк до новой строки и конца файла
		len++;
	if (s[fd][len] == '\n') //если это был символ конца строки, значит ещё не всё
	{
		*line = ft_strsub(s[fd], 0, len);//то начиная с 0 размера до len размера из s[fd] скатай на новую отдельную строку line.
		temp = ft_strdup(s[fd] + len + 1);//а всё оставшееся начиная с len размера скатай на temp;
		free(s[fd]);//освободи s[fd], чтобы 
		s[fd] = temp;//поместить туда уже укороченный файл
		if (s[fd][0] == '\0') //а если это уже мы дошли до конца строки, то удали просто его.
			ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\0') //если уже всё, то
	{
		if (text == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[255];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	int			text;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((text = read(fd, buffer, BUFF_SIZE)) > 0) 
	//читает файл порциями, пока файл не закончится
	//когда закончится - будет равен нулю. 
	{
		buffer[text] = '\0';
		//берет последний байт и присваивает туда конец строки
		if (s[fd] == NULL)
		//здесь идёт обращение к ячейке массива. Если внутри n-ой ячейки нет строки
			s[fd] = ft_strnew(1);
		//, то создается новая строка внутри массива под номером fd.
		temp = ft_strjoin(s[fd], buffer);
		//чтобы не потерять ссылку, мы созд переменную temp, которая будет содержать
		//всё из буффера и из s[fd], если она не пуста.
		free(s[fd]);//освобождаем её
		s[fd] = temp;//
		if (ft_strchr(buffer, '\n'))
		//если встретишь символ конца строки, то выйди из цикла
			break ;
	}
	if (text < 0) //если текст из файла не прочитался, то ошибка -1
		return (-1);
	else if (text == 0 && (s[fd] == NULL || s[fd][0] == '\0')) //если полностью прочелся, то 0.
		return (0);
	return (ft_new_line(s, line, fd, text)); //если что-то ещё есть, то 
}

int		main(void)
{
	int		i;
	int		fd;
	char	*line;
	
	i = 0;

	fd = open("test.txt", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	close(fd);
	return (0);
}