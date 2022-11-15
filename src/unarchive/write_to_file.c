#include "../../include/main_header.h"
#include <stdio.h>

int write_to_file(int archive_fd, int fd, int file_size)
{
    int result = 0;
    char burn02[512];
    char file_RnW_buffer[file_size];
    read(archive_fd, file_RnW_buffer, file_size);
    result = write(fd, file_RnW_buffer, file_size);
    read(archive_fd, burn02, 512 - file_size);
    close(fd);
    return result;
}
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