#include "../../include/main_header.h"
#include <stdio.h>

void archive_to_file(my_getopt_t *getopt_ptr)
{
    int archive_fd = 0, fd = 0, size_fd = 0;
    ph_t* ph;

    archive_fd = open(getopt_ptr->path_arr[0], O_RDONLY);

    do
    {
        ph = malloc(sizeof(ph_t));
        read_archive(archive_fd, ph);
        write(1, ph, 500); // test check;
        fd = open(ph->name, getopt_ptr->oflag, 0644);
        size_fd = my_ctoi(ph->size, my_strlen(ph->size));
        size_fd = oct_to_dec(size_fd);
        free(ph);
    }
    while (write_to_file(archive_fd, fd, size_fd) > 0); // NO !!!!!
    close(archive_fd);
}