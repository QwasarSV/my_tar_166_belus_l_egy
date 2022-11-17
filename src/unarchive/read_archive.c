#include "../../include/main_header.h"
#include <stdio.h>

ph_t* read_archive(int fd, ph_t* ph)
{   
    read(fd, ph, sizeof(ph_t));
    char burn[12];
    read(fd, burn, 12);
    return ph;
}