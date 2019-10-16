#include "get_next_line.h"

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putchar('\n');
	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putchar('\n');
	return 0;
}
