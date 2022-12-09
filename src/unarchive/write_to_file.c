#include "../../include/main_header.h"
#include <stdio.h>

int write_to_file(int archive_fd, int fd, int file_size)
{
    int byte_count = 0, initial_size = 0, block_size = 0;
    char burn02[BLOCKSIZE - (file_size % BLOCKSIZE)];
    char buff[file_size];

    block_size = define_block_size(file_size);

    byte_count = write_chunk02(fd, archive_fd, buff, block_size, file_size);

    read(archive_fd, burn02, BLOCKSIZE - (file_size % BLOCKSIZE));
    close(fd);

    return byte_count;
}
//replaced by write_chunk02
    // while (result < file_size && (initial_size = read(archive_fd, file_RnW_buffer, block_size)))
    // {
    //     result += write(fd, file_RnW_buffer, initial_size);

    //     if (file_size > SIZE && file_size - result < SIZE)
    //     {
    //         block_size = file_size - result;
    //     }
    // }