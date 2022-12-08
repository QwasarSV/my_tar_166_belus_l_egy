#include "../../include/main_header.h"
#include <stdio.h>

int read_to_pos(int archive_fd, int size_read, my_getopt_t* getopt_ptr) //potential unused arguments need to make a new function; 
{
    int byte_count = 0, initial_size = 0, block_size = SIZE;
    char buff[size_read];
    char burn[SIZE - (size_read%SIZE)];

    block_size = define_block_size(size_read);
    printf("rtp - size file %i\n", size_read);
    byte_count = read_chunk02(archive_fd, buff, block_size, size_read);
    printf("byte_count - read_chunk: %i\n", byte_count);

    if (size_read % SIZE != 0)
    {
        printf("byte_count - padding: %i\n",SIZE - (size_read%SIZE) );
        byte_count += read(archive_fd, burn, SIZE - (size_read%SIZE));
    }

    return byte_count;
}

    // if(size_read%SIZE == 0){
    //     read(archive_fd, burn, SIZE);
    // }



    // replaced by read_chunk02
    // while (byte_read < size_read)
    // {
    //     byte_read += read(archive_fd, buff, block_size);

    //     if (size_read > SIZE && size_read - byte_read < SIZE)
    //     {
    //         block_size = size_read - byte_read;
    //     }
    // }