#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int    main(void)
{
    int        fd;

    fd = open("./gnlTester/files/42_with_nl", O_RDONLY);
    printf("---BEGIN---\n");
    printf("|%s|", get_next_line(fd));
    printf("|%s|", get_next_line(fd));
    printf("|%s|", get_next_line(fd));
    printf("|%s|", get_next_line(fd));
    printf("|%s|", get_next_line(fd));
    printf("|%s|", get_next_line(fd));
    printf("|%s|", get_next_line(fd));
    printf("\n---END---");
}