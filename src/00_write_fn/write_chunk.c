#include "../../include/main_header.h"

int write_chunk(int fd, int archive_fd, char* buff, int block_size) // USED IN WRITE_TO_ARCHIVE.C replaced with write_chunk02
{
    int initial_size = 0, byte_count = 0;

    while ((initial_size = read(fd, buff, block_size)))
    {
        byte_count += write(archive_fd, buff, initial_size);
        
    }

    return byte_count;
}

int write_chunk02(int fd, int archive_fd, char* buff, int block_size, int file_size) // USED IN WRITE_TO_FILE.C
{
    int byte_count = 0, initial_size = 0; 

    while (byte_count < file_size 
    && (initial_size = read(archive_fd, buff, block_size)))
    {
        byte_count += write(fd, buff, initial_size);
        if (file_size > SIZE && file_size - byte_count < SIZE)
        {
            block_size = file_size - byte_count;
        }
    }
    return byte_count;
}