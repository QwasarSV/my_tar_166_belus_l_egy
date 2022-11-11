#include "../../include/main_header.h"
#include <stdio.h>

void read_archive(int fd, ph_t* ph)
{   
    int result = 0;
    
    read(fd, ph, sizeof(ph_t));
    char burn00[12];
    read(fd, burn00, 12);
    result = oct_to_dec(my_ctoi(ph->size, my_strlen(ph->size)));
    printf("result : %i\n", result);
    
    //char burn[result + 512];
    char burn[512];
    //read(fd,burn,(result + 512));
    read(fd,burn,(512));
   // return ph;
}

void test_archive(int fd, ph_t* ph)
{   
    int result = 0;
    
    read(fd, ph, sizeof(ph_t));
    char burn00[12];
    read(fd, burn00, 12);
    result = my_ctoi(ph->size, my_strlen(ph->size));
    printf("result : %i\n", result);
    
    //char burn[result + 512];
    char burn[512];
    //read(fd,burn,(result + 512));
    read(fd,burn,(512));
   // return ph;
}