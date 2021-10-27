#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{

    int fd = open("./test.txt", O_RDONLY);
    printf("%s|\n",get_next_line(fd));
    printf("%s|\n",get_next_line(fd));
    printf("%s|\n",get_next_line(fd));
    printf("%s|\n",get_next_line(fd));
}