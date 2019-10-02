
#include "get_next_line.h"

/*
** Allocates sufficccient memory for a copy of the string s1, does the copy,
** and returns a pointer to it.
*/

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
** Verify if whatever is in the stack, has a newline. If it doesn't, returns
** a zero (0) to indicate that it's not valid. If there is a newline, we make a
** copy of the stack into the line, and we copied whatever was in the stack
** before, back to the stack (with the temporary stack that we created).
*/

static int			gnl_verify_line(char **stack, char **line)
{
	char			*tmp_stack; //Чтобы временно хранить адрес где остановились.
	char			*strchr_stack;//чтобы читать;
	int				i;//счётчик

	i = 0;
	strchr_stack = *stack;//1.берем содержимое от стэка для чтения
	while (strchr_stack[i] != '\n')//2.читаем его до символа след строки
		if (!strchr_stack[i++]) //3.если не находит, то возвращает нуль.
			return (0);
	tmp_stack = &strchr_stack[i]; //4.Чтобы временно сохранить позицию где остановились;
	//5. И вот если встретил символ след строки, то берем адрес этого индекса и присваиваем туда конец строки.
	*tmp_stack = '\0';
	*line = ft_strdup(*stack);//6.отправляем на ft_strdup, чтобы выделилась память из оперативки и 
	//скопировалась линия до символа КОНЦА СТРОКИ уже. 
	*stack = ft_strdup(tmp_stack + 1);//Создаем новую память опер. память и копируем содержимое с момента где остановились
	//и присваиваем обратно в стэк.
	return (1);
}

/*
** Reads into the heap, from the file descriptors, a specific number of bytes
** defined by the BUFF_SIZE macro in the get_nex_line.h file. It's going to
** continue the reading when the return value of the read function is greater
** than zero (no errors, or if there is nothing else to read).
** If there is something in the stack, we will concatinate whatever is in
** there, with whatever is read in the heap. If no, we will just add
** whatever is in the heap into the stack. Then we will verify the stack to
** see if there is a newline. If there is, we will break from the while loop
** and force the positive ret value into a one (1), using the RET_VALUE() macro.
** This answer form SO helped me visualize the stack and heap in a better way:
** http://stackoverflow.com/a/1213360
*/

static	int			gnl_read_file(int fd, char *heap, char **stack, char **line)
{
	int				ret;
	char			*tmp_stack;

	while ((ret = read(fd, heap, BUFF_SIZE)) > 0) 
		//1.Пока файл читается. А раз он читается, то рет будет
		//равен числу байт, которому равен файл. Если успешно читается, 
		//то выполняется следующее;
	{
		heap[ret] = '\0'; 
		//2.т.к. рэт будет равен кол-ву байт, тем самым перейдем 
		//мы к последнему символу, то сразу ставим символ конца строки
		if (*stack) //3.если стэк нам пришёл, то
		{
			tmp_stack = *stack; //присвоили содержание буфера
			//сохр начальное содержание от стэк
			*stack = ft_strjoin(tmp_stack, heap);
			//чтобы объединить его с нашей кучей, заполненный нулём
			free(tmp_stack);
			//очищаем временный стэк;
			tmp_stack = NULL;
			//и для безопасности обнуляем;
		}
		else
			*stack = ft_strdup(heap);
		//а если стэк не пришёл с содержимым, то кучу с размером в буфе
		//отправляем для созд новой строки за счёт опер памяти и 
		//присваиваем стэку
		if (gnl_verify_line(stack, line)) //отпр-ем в функцию, которая ищет симв 
			//конца строки и копирует его в line;
			break ;
	}
	return (RET_VALUE(ret));//т.е. если прочлось, то возвр 1, а если нет, то 0;
}

/*
** This is where the real shit happens.
** It first checks for errors (is the line is empty, if the number of the file
** descriptor is invalid, or if it fails to allocate the heap), so it can return
** a minus one (-1) if needed.
**
** If there is something in the stack (because we are using a static variable),
** we verify that there is a newline. If not, we allocate memory for the heap,
** and we read the file.
**
** When the reading of the file ends, we will free the heap (we're not gonna
** use it anymore), and we check for the value of ret (if it's 1 or -1, return
** that, if the stack is empty, return 0). If neither of these conditions are
** valid, we assing line to the value of the stack, free the stack, and return 1
**
** A good read about file descriptors:
** http://www.bottomupcs.com/file_descriptors.xhtml
*/

int					get_next_line(int const fd, char **line)
{
	static char		*stack[FD_MAX]; //Именно статическую, постоянную, где будет всё содержимое нашего файла.
	char			*heap; //Для кучи
	int				ret;
	int				i;

	if (!line || (fd < 0 || fd >= FD_MAX) || (read(fd, stack[fd], 0) < 0) \
		|| !(heap = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
	/*1.Если не пришла line  ИЛИ нет файлового дескриптора ИЛИ файловый десрикптор
	 * больше максимального значения ИЛИ чтение не удалось ИЛИ не выделилась
	 * память для кучи с размером BUFF_SIZE (он нужен для того, чтобы определить
	 * размер порций, которыми он будет загружать из файлового дескриптора 
	 * содержимое нашего файла.*/
		//!ВАЖНО отметить, что мы уже здесь прочитываем наш файл и копируем содержимое в stack[fd], который и есть наш буфер.
		//Почему fd? чтобы выделилось именно столько, чтобы хватило для вмещения всего содержимого.
		return (-1); //то возвращаем -1;
	if (stack[fd]) //2.обращаемся к нашему файлу
		if (gnl_verify_line(&stack[fd], line)) //3.определяем линию, 
			//отправив аргументами наш стэк под номером файлового декр-ра
			//и принятую нами линию. Там опр-ся симв. новой строки и скопируется в переменную line.
			return (1); // если не получается - то возвр-м именно 1.
	i = 0;
	while (i < BUFF_SIZE) 
		heap[i++] = '\0';//4.Мы выделяли память в строке 147 и теперь его заполняем просто нулями. 
	ret = gnl_read_file(fd, heap, &stack[fd], line);
	//5. отправляем дескриптор, нашу кучу обнулённую, стэк с индексом дескриптора и линию
	free(heap);
	if (ret != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}

int				main(int argc, char **argv)
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	printf("%s", line);
	return (0);
}
