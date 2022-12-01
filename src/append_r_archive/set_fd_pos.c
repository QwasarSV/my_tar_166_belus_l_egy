#include "../../include/main_header.h"
#include <stdio.h>

/* UNDESIRED SOLUTION

OBJECTIF: FIND FILENAME ABSENT FROM ARCHIVE.

REQUIREMENT TO COMPLETE U FLAG, 
    STORE FILENAME INTO ARRAY:
    - OPEN ARCHIVE
    - GET NB OF STRING AND SIZE;
    - CLOSE ARCHIVE
    - OPEN ARCHIVE
    - STORE STRINGS ON ARRAY IN MEMORY 
    - CLOSE ARCHIVE
    - CHECK STRING ARRAY AGAINST INPUT
*/
int set_fd_pos(int archive_fd, my_getopt_t *getopt_ptr) // similar function to "archive to file" == need to change accepted args or function structure so it can be more polyvalent.
{
    int size_fd = 0, block_count = 0, inter_byte_count = 0, byte_count = 0;
    ph_t* ph;
    char *filename = malloc(sizeof(char)*100);
    int tmp_fd = open(getopt_ptr->path_arr[0], getopt_ptr->oflag , 0644);
    int count_str = 0;

    do
    {
        ph = malloc(sizeof(ph_t));
        read_archive(tmp_fd, ph);
        size_fd = my_ctoi(ph->size, my_strlen(ph->size));
        size_fd = oct_to_dec(size_fd);
        my_strcpy(filename, ph->name);
        filename[0] != '\0' ? count_str += 1 : count_str;
        byte_count += size_fd + size_fd % SIZE + SIZE;
        free(ph);
    }
    while (read_to_pos(tmp_fd, size_fd, getopt_ptr, filename) > 0);

    my_bzero(filename, my_strlen(filename));
    read_to_pos(archive_fd, byte_count, getopt_ptr, filename);

    if (size_fd%SIZE == 0)
    {
        byte_count += SIZE;
    }

    //byte_count += SIZE;
    block_count = byte_count/SIZE;
    close(tmp_fd);
    return block_count;
}