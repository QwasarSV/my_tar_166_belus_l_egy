#include "../../include/main_header.h"
#include <stdio.h>

void files_to_archive_u(my_getopt_t *getopt_ptr, node_t* m_head)
{
    int fd = 0, archive_fd = 0, index = 0, block_count = 0;
    ph_t* ph;
    my_tar_struct* tar_s = malloc(sizeof(my_tar_struct));
    archive_fd = open(getopt_ptr->path_arr[index], getopt_ptr->oflag , 0644);

    if (getopt_ptr->bool_arr[2] == true || getopt_ptr->bool_arr[4] == true)
    {
        block_count += set_fd_pos_u(archive_fd , m_head, getopt_ptr, tar_s);
    }

    while (index < getopt_ptr->nbr_str -1) // evolution: need to be based on valid nodes or valid strings == need security check
    {
        index++;
        
        ph = malloc(sizeof(ph_t));
        ph = fill_ph(m_head->daughter_head, ph, getopt_ptr->path_arr[index]);
        
        getopt_ptr->state[index] = check_mtime(ph, tar_s, getopt_ptr);
        printf("state but main fn : %i\n",getopt_ptr->state[index]);
        if (getopt_ptr->state[index] == true )
        {
            fd = open(getopt_ptr->path_arr[index], O_RDONLY);
            printf("strpath %s", getopt_ptr->path_arr[index]);
            block_count += write_to_archive(fd, archive_fd, ph);
        }
        free(ph);
    }

    printf("countblock : %i \n", block_count);

    end_block(archive_fd, block_count);

    close(archive_fd);
}
        //printf("nbrstr : %i\n", getopt_ptr->nbr_str);
        //printf("path : %s\n", getopt_ptr->path_arr[index]);
        // printf("name : %s\n", ph->name);
        // printf("size : %s\n", ph->size);