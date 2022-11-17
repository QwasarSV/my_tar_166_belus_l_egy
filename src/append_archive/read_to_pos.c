#include "../../include/main_header.h"
#include <stdio.h>

int read_to_pos(int archive_fd, int size_read)
{
    int byte_read = 0, initial_size = 0, block_size = SIZE;
    char buff[size_read];
    char burn[SIZE - (size_read%SIZE)];
    
    block_size = define_block_size(size_read);

    while (byte_read < size_read )
    {
        byte_read += read(archive_fd, buff, block_size);
        
        if (size_read > SIZE && size_read - byte_read < SIZE)
        {
            block_size = size_read - byte_read;
        }
    }

    if (size_read != 0)
    {
        read(archive_fd, burn, SIZE - (size_read%SIZE));
    }

    if(size_read%SIZE == 0){
        read(archive_fd, burn, SIZE);
    }

    return byte_read;
}