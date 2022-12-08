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

void tar_map_file(int byte_count, my_tar_struct* tar_s)
{
    while (byte_count > 0)
    {
        tar_s->tar_map[tar_s->index] = 2;
        tar_s->index += 1;
        byte_count -= SIZE;
    }
}

int read_chunk02(int fd, char* buff, int block_size, int file_size)
{
    int byte_count = 0;
    while (byte_count < file_size)
    {
        byte_count += read(fd, buff, block_size);

        if (file_size > SIZE && file_size - byte_count < SIZE)
        {
            block_size = file_size - byte_count;
        }
    }
    return byte_count;
}

int read_chunk03(int fd, char* buff, int block_size, int size_file, my_tar_struct* tar_s)
{
    int byte_count = 0, index = 0;
    ph_t* ph;
    while (byte_count < size_file)
    {
        if (tar_s->tar_map[tar_s->index] == 1)
        {
            ph = malloc(sizeof(ph_t));
            read_header(fd, ph);
            byte_count += SIZE;
            store_filenames(tar_s, ph->name, ph->mtime, index);
            index +=  1;
            free(ph);
        }
        else
        {
            byte_count += read(fd, buff, block_size);
        }

        if (size_file > SIZE && size_file - byte_count < SIZE)
        {
            block_size = size_file - byte_count;
        }
        tar_s->index += 1;
    }
    return byte_count;
}