#include "../../include/main_header.h"
#include <stdio.h>

int read_to_pos(int archive_fd, int size_read, my_getopt_t* getopt_ptr, char* ph_name) //potential unused arguments need to make a new function; 
{
    int byte_read = 0, initial_size = 0, block_size = SIZE;
    char buff[size_read];
    char burn[SIZE - (size_read%SIZE)];

    block_size = define_block_size(size_read);

    while (byte_read < size_read)
    {
        byte_read += read(archive_fd, buff, block_size);

        if (size_read > SIZE && size_read - byte_read < SIZE)
        {
            block_size = size_read - byte_read;
        }
    }

    // if(getopt_ptr->bool_arr[4] == true)
    // {
    //     check_u_state(ph_name, getopt_ptr, buff, size_read);
    // }

    if (size_read != 0)
    {
        read(archive_fd, burn, SIZE - (size_read%SIZE));
    }

    // if(size_read%SIZE == 0){
    //     read(archive_fd, burn, SIZE);
    // }

    return byte_read;
}