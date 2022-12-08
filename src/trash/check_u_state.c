#include "../../include/main_header.h"
#include <stdio.h>

// NEED TO READ IN CHUNKS

int check_u_state(char* filename_ph, my_getopt_t* getopt_ptr, char* archive_buff, int size_fd) // similar function to "archive to file" == need to change accepted args or function structure so it can be more polyvalent.
{
    char buff[size_fd];
    int index = 0;
    int fd;
    char tmp_arch_buf[size_fd +1];
    char tmp_buf[size_fd +1];
    index = 0;

    while (index < getopt_ptr->nbr_str -1)
    {
        index += 1;

        if (my_strcmp(filename_ph, getopt_ptr->path_arr[index]) == 0)
        {
            fd = open(getopt_ptr->path_arr[index],O_RDONLY, 0644);
            read(fd, buff, size_fd);
            // tmp_buf[size_fd ] = '\0';
            // tmp_arch_buf[size_fd ] = '\0';
            my_strncpy(tmp_arch_buf, archive_buff,size_fd );
            my_strncpy(tmp_buf, buff, size_fd);
            //printf("buffstr %s\n",buff);
            //printf("archive_buff %s\n",buff);
            if (my_strcmp(tmp_buf, tmp_arch_buf) != 0)
            {
                getopt_ptr->state[index] = true;
                close(fd);
                return 1;
            }
        }
    }
    //getopt_ptr->state[index] = false;
    return 0;
}