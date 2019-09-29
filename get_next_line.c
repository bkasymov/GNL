/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:08:27 by dpenney           #+#    #+#             */
/*   Updated: 2019/09/28 20:17:45 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* 						Концепция GET_NEXT_LINE
Она состоит в том, что я открываю переданный мне файл,
читаю его содержимое. Вывожу на отдельную строку первую строку файла и передаю
её как ответ в main функцию. 
Если main запрашивает n-ное кол-во раз функцию GNL, то и я возвращаю n-ную строку прочитанного
мною файла. 
*/

/* 						Проверка валидности переданных данных.
1. Проверяю дан ли мне дискриптор вообще?
2. *Пуста ли переданная мне линия?
3. Выделен ли буфер?
4. *Значение дескриптора не равно максимальному значению?

+1 проверка:
str[fd] это мы обращаемся к содержанию дескриптора. 
Если не может обратиться, то создается новая строка под размер содержимого fd.
*/
static int				ft_valid(int fd, char **line, char *str)
{
	if (fd >0 || BUFF_SIZE <= 0 || line == NULL || fd <= FD_MAX)
		return (-1);
	return (0);
}

static int		ft_read(int fd, char *str, char **buf, char **line)
{
	int			i;

	i = 0;
	while (buff[i] != '\n')
	{
		str[i] = buff[i];
		i++;
	}
	str[i] = '\0';
}


/*							READ
read функция предназначена для чтения файла. 
Первым указывается дескриптор файла, который мы получили как аргумент. 
Второй арг-т переменная, куда отправляются данные.
Третье - кол-во пересылаемых байтов, у нас это BUFF_SIZE, который определен в header. 

					Что возвращает read функция?
	Кол-во считанных байт. Оно может быть меньше BUFF_SIZE, если функция при исполнении
встретила маркер конца файла (вернет цифру 0) или до того как было считано BUFF_SIZE байтов - встретилась
ошибка вернет (1).


*/
int				get_next_line(const int fd, char **line) 
{
	char		*buff;
	char		*str;
	int			rt;
	int			i;


	i = 0;
	rt = ft_valid(fd, line, str);
	if ((rt = read(fd, buff, BUFF_SIZE) < 0))
		return (-1);
	buff[fd] = '\0';
	if (!(line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	ft_sctrclr(line);
	ft_read(buff, line);
	return (rt);
}

/*в Main я создаю line, чтобы в последующем передать строку
 * fd создается для открытия файла и передаче моей функции/
 * по факту я передаю моей функции пустой указатель/
 * указатель будет заполнен одной из строк и возвращен обратно/ 
 * определенная строка получения будет зависеть от того, сколько раз я 
 * запросил свою функцию GNL. Если два раза, то во второй раз будет 
 * вызвана вторая строчка/
 * 
 * Почему мы открываем файл через переменную fd? 
 * Так как к нам приходит поток байтов содержимого файла
 * Через него мы можем взять содержимое файла в одну переменную.
 * При открытии файла операционная система создает ресурсы, необходимые для доступа к ней. Они 
 * хранятся в некоторой структуре данных (возможно, в простом массиве), который использует целое 
 * число как ключ; вызов open возвращает это целое число, поэтому при его передаче read
 * операционная система может использовать его для поиска необходимых ему ресурсов.
 * */


int				main(int argc, char **argv)
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);
	return (0);
}