#include "get_next_line.h"

int     main(int argc, char **argv)
{
    if (argc >= 2)
    {
        int fd;
        char *line;
        fd = 0;

        fd = open("test.txt", O_RDONLY);
        get_next_line(fd, &line);
        ft_putstr(line);
        close(fd);


        return (0);
    }
    return (0);
}