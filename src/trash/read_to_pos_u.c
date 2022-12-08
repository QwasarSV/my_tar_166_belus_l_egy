#include "../../include/main_header.h"
#include <stdio.h>

// int read_to_pos_u(int archive_fd, int size_read, my_tar_struct* tar_s) //potential unused arguments need to make a new function; 
// {
//     int byte_count = 0, initial_size = 0, block_size = SIZE, index = 0;
//     char buff[size_read];
//     char burn[SIZE - (size_read%SIZE)];

//     block_size = define_block_size(size_read);

//     byte_count = read_chunk03(archive_fd, buff, block_size, size_read, tar_s);

//     if (size_read != 0)
//     {
//         read(archive_fd, burn, SIZE - (size_read%SIZE));
//     }

//     return byte_count;
// }


//replaced by read_chunk03
    // while (byte_read < size_read)
    // {
    //     if (tar_s->tar_map[tar_s->index] == 1)
    //     {
    //         ph = malloc(sizeof(ph_t));
    //         read_archive(archive_fd, ph);
    //         byte_read += SIZE;
    //         store_filenames(tar_s, ph->name, ph->mtime, index);
    //         index +=  1;
    //     }
    //     else
    //     {
    //         byte_read += read(archive_fd, buff, block_size);
    //     }

    //     if (size_read > SIZE && size_read - byte_read < SIZE)
    //     {
    //         block_size = size_read - byte_read;
    //     }
    //     tar_s->index += 1;
    // }



