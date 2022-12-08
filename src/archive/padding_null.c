#include "../../include/main_header.h"
#include <stdio.h>

int padding_null(int fd, int size) 
{
    char padding[SIZE] = {'\0'};
    write(fd, padding, SIZE - size);
    return (SIZE - size);
    // if(size == 512) {
    //     write(fd, padding, SIZE);
    // }
    // else
    // {
        
    // }
}