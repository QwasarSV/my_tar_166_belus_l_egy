#include "../../include/main_header.h"
#include <stdio.h>

int write_to_file(int archive_fd, int fd, int file_size)
{
    int result = 0, initial_size = 0, block_size = 0;
    char burn02[SIZE - (file_size%SIZE)];

    char file_RnW_buffer[file_size];

    block_size = define_block_size(file_size);

    while (result < file_size && (initial_size = read(archive_fd, file_RnW_buffer, block_size)))
    {
        result += write(fd, file_RnW_buffer, initial_size);
        
        if (file_size > SIZE && file_size - result < SIZE)
        {
            block_size = file_size - result;
        }
    }

    read(archive_fd, burn02, SIZE - (file_size%SIZE));
    close(fd);
    return result;
}


    // while ((initial_size = read(fd, file_RnW_buffer, size_block)))
    // {
    //     write(archive_fd, file_RnW_buffer, size_block);
    //     count_block += 1;
    //     printf("name block %s count block%i\n",ph->name,count_block);





    // (void)write_fd;
    // int result = 0;
    // char burn01[500];
    // char burn00[12];
    // char burn02[512];
    // read(fd, burn01, 500);
    // read(fd, burn00, 12);
    // char file_RnW_buffer[file_size];   
    // read(fd, file_RnW_buffer, file_size);
    
    // result = write(write_file_fd, file_RnW_buffer, file_size);
    
    // read(fd, burn02, 512 - file_size);
    
    // close(write_file_fd);
    // return result;