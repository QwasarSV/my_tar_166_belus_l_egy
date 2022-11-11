#include "../../include/main_header.h"
#include <stdio.h>
void write_to_archive(int fd, int write_fd, int write_archive_fd, ph_t* ph)
{ (void)ph;
    int size_block = 0, size_fd = 0, initial_size = 0;
    char file_RDON_buffer[SIZE];

    while ((size_block = read(fd, file_RDON_buffer, SIZE)))
    {
        size_fd = size_fd + size_block;
    }

    char file_RnW_buffer[size_fd];
        printf("ph name : %s\n", ph->name);
        printf("ph size : %s\n", ph->size);
    //write_struct(write_archive_fd, ph);
    write(write_archive_fd, &(*ph), sizeof(ph_t));
    
    char buff[12] = {'\0'};
    write(write_archive_fd, buff, 12);

    while ((initial_size = read(write_fd, file_RnW_buffer, size_fd)))
    {
        write(write_archive_fd, file_RnW_buffer, size_fd);
    }
    printf("size fd :%i\n",size_fd);
    padding_null(write_archive_fd, size_fd); 
    
    close(fd);
    close(write_fd);
    close(write_archive_fd);
}