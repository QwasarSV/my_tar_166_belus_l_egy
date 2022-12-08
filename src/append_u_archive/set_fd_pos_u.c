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

int set_fd_pos_u(int archive_fd, node_t* m_head, my_getopt_t *getopt_ptr, my_tar_struct* tar_s) // similar function to "archive to file" == need to change accepted args or function structure so it can be more polyvalent.
{
    int size_fd = 0, block_count = 0, inter_byte_count = 0, byte_count = 0;
    ph_t* ph;

    int tmp_fd = open(getopt_ptr->path_arr[0], getopt_ptr->oflag , 0644);
//------------------------
    int archive_blck_size = 0;

    archive_blck_size = get_archive_size(m_head, getopt_ptr);
    init_tar_map(tar_s, archive_blck_size);
//------------------------
    byte_count = read_archive03(tmp_fd, getopt_ptr, tar_s);

    tar_s->str_arr = malloc(sizeof(char*)*tar_s->nbr_str);
    tar_s->mtim_arr = malloc(sizeof(char*)*tar_s->nbr_str); 
    tar_s->index = 0;

    //my_bzero(filename, my_strlen(filename));

    //read_to_pos_u(archive_fd, byte_count, tar_s);
    map_archive(archive_fd, byte_count, tar_s);
    check_file_arr(getopt_ptr, tar_s);
    int index = 0;
    printf("\n state arr : ");

    if (size_fd%SIZE == 0)
    {
        byte_count += SIZE;
    }

    // byte_count += SIZE;
    block_count = byte_count/SIZE;
    close(tmp_fd);
    return block_count;
}



// int set_fd_pos(int archive_fd, my_getopt_t *getopt_ptr) // similar function to "archive to file" == need to change accepted args or function structure so it can be more polyvalent.
// {
    // int size_fd = 0, block_count = 0, inter_byte_count = 0, byte_count = 0;
    // ph_t* ph;
// 
    // int tmp_fd = open(getopt_ptr->path_arr[0], getopt_ptr->oflag , 0644);
// 
    // byte_count = read_archive02(tmp_fd, getopt_ptr);
// 
    // read_to_pos(archive_fd, byte_count, getopt_ptr);
// 
    // if (size_fd%SIZE == 0)
    // {
        // byte_count += SIZE;
    // }
// 
    // byte_count += SIZE;
    // block_count = byte_count/SIZE;
    // close(tmp_fd);
    // return block_count;
// }




//replaced by reach_archive03
    // do
    // {
    //     ph = malloc(sizeof(ph_t));
    //     read_header(tmp_fd, ph);
    //     size_fd = my_ctoi(ph->size, my_strlen(ph->size));
    //     size_fd = oct_to_dec(size_fd);
    //     tar_s->tar_map[tar_s->index] = 1;
    //     my_strcpy(filename, ph->name);
    //     tar_s->nbr_str += 1;
    //     byte_count += size_fd + size_fd % SIZE + SIZE;
    //     free(ph);
    //     tar_s->index += 1;
    // }
    // while (filename[0] != '\0' && map_archive(tmp_fd, size_fd, getopt_ptr, filename, tar_s) > 0);






    // int index = 0;
    // printf("tarmap index%i\n",tar_s->index);
    // printf("\n tar map : ");
    // while (index < archive_blck_size-1)
    // {
    //     printf("%i-",tar_s->tar_map[index]); 
    //     index +=1;
    // }
    // printf("\n"); 