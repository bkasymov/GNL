#include "get_next_line.h"
#include <stdio.h>

int     main(void)
{

        int fd;
        char *line;
        fd = 0;

        fd = open("test.txt", O_RDONLY);
        get_next_line(fd, &line);
        printf("%s\n", line);
        close(fd);
        return (0);
}
