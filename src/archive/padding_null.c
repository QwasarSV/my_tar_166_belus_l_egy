#include "../../include/main_header.h"
#include <stdio.h>

void padding_null(int fd, int size) 
{
    char padding[512] = {'\0'};
    write(fd, padding, SIZE - size);
}