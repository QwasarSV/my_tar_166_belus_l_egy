#include "../../include/main_header.h"
#include <stdio.h>

void read_archive(int archive_fd, my_getopt_t* getopt_ptr)
{
    int fd = 0, size_file = 0;
    ph_t* ph;
    do
    {
        ph = malloc(sizeof(ph_t));
        read_header(archive_fd, ph);

        fd = open(ph->name, getopt_ptr->oflag, 0644);
        
        //printf("print fd %i \n", fd);

        size_file = my_ctoi(ph->size, my_strlen(ph->size));
        size_file = oct_to_dec(size_file);
        
        if (getopt_ptr->bool_arr[3] == 1 && ph->name[0] != '\0')
        {
            int len = my_strlen(ph->name) +1;
            my_strcat(ph->name, "\n");
            write(1, ph->name, len);
        }
        free(ph);
    }
    while (write_to_file(archive_fd, fd, size_file) > 0);
}