#include "../../include/main_header.h"
#include <stdio.h>

int map_archive(int archive_fd, int size_read, my_tar_struct* tar_s) //potential unused arguments need to make a new function; 
{
    int byte_count = 0, initial_size = 0, block_size = SIZE;
    char buff[size_read];
    char burn[SIZE - (size_read%SIZE)];

    block_size = define_block_size(size_read);

    switch (tar_s->tar_state)
    {
    case 0:
        byte_count = read_chunk02(archive_fd, buff, block_size, size_read);
        break;
    case 1:
        byte_count = read_chunk03(archive_fd, buff, block_size, size_read, tar_s);
        break;

    }

    if (size_read != 0)
    {
        read(archive_fd, burn, SIZE - (size_read%SIZE));
    }

    if (tar_s->tar_state == 0 )
    {
        if(size_read%SIZE == 0){
            read(archive_fd, burn, SIZE);
            tar_s->index += 1;
        }
    }
    return byte_count;
}


// replaced by read_chunk02
    // while (byte_read < size_read)
    // {
    //     byte_read += read(archive_fd, buff, block_size);
    //     tar_s->tar_map[tar_s->index] = 2;
    //     tar_s->index += 1;
    //     if (size_read > SIZE && size_read - byte_read < SIZE)
    //     {
    //         block_size = size_read - byte_read;
    //     }
    // }