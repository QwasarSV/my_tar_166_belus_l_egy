#include "../../include/main_header.h"
#include <stdio.h>

int write_header(int fd, char* buff, ph_t* ph)
{   
    char burn[12] = {'\0'};
    write(fd, &(*ph), sizeof(ph_t));
    write(fd, burn, 12);
    return SIZE;
}