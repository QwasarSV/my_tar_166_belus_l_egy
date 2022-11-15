#include "../../include/main_header.h"
#include <stdio.h>

void files_to_archive(my_getopt_t *getopt_ptr, node_t* m_head) 
{
    int fd = 0, archive_fd = 0, index = 0, count_block = 20;
    
    ph_t* ph;

    archive_fd = open(getopt_ptr->path_arr[index], O_RDWR | O_APPEND | O_CREAT, 0644);
    
    while (index < getopt_ptr->nbr_str -1) // evolution: need to be based on valid nodes or valid strings == need security check
    {
        index++;
        ph = malloc(sizeof(ph_t));
        ph = fill_ph(m_head->daughter_head, ph, getopt_ptr->path_arr[index]);
        fd = open(getopt_ptr->path_arr[index], O_RDONLY);
        count_block -= write_to_archive(fd, archive_fd, ph);
        free(ph);
    }
    printf("countblock : %i \n", count_block);
    while(count_block > 0)
    {
        padding_null(archive_fd, 0);
        count_block -= 1;
    }
    close(archive_fd);
}
        //printf("nbrstr : %i\n", getopt_ptr->nbr_str);
        //printf("path : %s\n", getopt_ptr->path_arr[index]);
        // printf("name : %s\n", ph->name);
        // printf("size : %s\n", ph->size);