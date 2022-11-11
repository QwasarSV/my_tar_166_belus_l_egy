#include "../../include/main_header.h"
#include <stdio.h>

void files_to_archive(my_getopt_t *getopt_ptr, node_t* m_head) 
{
    int fd = 0, write_fd = 0, write_archive_fd = 0, ref = 0, index = 0 ;
    ref = index;
    ph_t* ph;
    printf("nbrstr : %i\n", getopt_ptr->nbr_str);
    
    while (index < getopt_ptr->nbr_str -1)
    {
        index++;
        ph = malloc(sizeof(ph_t));
        ph = fill_ph(m_head->daughter_head, ph, getopt_ptr->path_arr[index]);
        // printf("path : %s\n", getopt_ptr->path_arr[index]);
        // printf("name : %s\n", ph->name);
        // printf("size : %s\n", ph->size);
        fd = open(getopt_ptr->path_arr[index], O_RDONLY);
        write_fd = open(getopt_ptr->path_arr[index], O_RDONLY);
        write_archive_fd = open(getopt_ptr->path_arr[ref], O_RDWR | O_APPEND | O_CREAT, 0644);
        write_to_archive(fd, write_fd, write_archive_fd, ph);
        free(ph);
    }
}