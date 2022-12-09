#include "../../include/main_header.h"

// int read_chunk(int fd, char* buff, int block_size, int size_file)
// {
//     int byte_count = 0;
//     while (byte_count < size_file)
//     {
//         byte_count += read(fd, buff, block_size);

//         if (size_file > SIZE && size_file - byte_count < SIZE)
//         {
//             block_size = size_file - byte_count;
//         }
//     }
//     return byte_count;
// }

