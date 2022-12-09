#include "../../include/main_header.h"
#include <stdio.h>

int set_fd_pos(int archive_fd, my_getopt_t *getopt_ptr) // similar function to "archive to file" == need to change accepted args or function structure so it can be more polyvalent.
{
    int block_count = 0, byte_count = 0;

    int tmp_fd = open(getopt_ptr->path_arr[0], getopt_ptr->oflag , 0644);
    byte_count += read_archive02(tmp_fd);
    close(tmp_fd);
    //printf("byte_count main %i \n",byte_count);

    read_to_pos(archive_fd, byte_count - BLOCKSIZE);
    byte_count -= 512;
    block_count = byte_count/BLOCKSIZE;

    return block_count;
}

// replaced by read_archive02
    // do
    // {
    //     ph = malloc(sizeof(ph_t));
    //     read_header(tmp_fd, ph);
    //     size_fd = my_ctoi(ph->size, my_strlen(ph->size));
    //     size_fd = oct_to_dec(size_fd);
    //     my_strcpy(filename, ph->name);
    //     filename[0] != '\0' ? count_str += 1 : count_str;
    //     byte_count += size_fd + size_fd % SIZE + SIZE;
    //     free(ph);
    // }
    // while (read_to_pos(tmp_fd, size_fd, getopt_ptr, filename) > 0);