#include "../../include/main_header.h"
#include <stdio.h>

// NEED TO READ IN CHUNKS

int check_mtime(ph_t* ph, my_tar_struct* tar_s, my_getopt_t* getopt_ptr) // similar function to "archive to file" == need to change accepted args or function structure so it can be more polyvalent.
{
    int index = 0;
    while (index < tar_s->nbr_str -1)
    {
        if (my_strcmp(ph->name, tar_s->str_arr[index]) == 0)
            {
                int file_mtim = my_ctoi(ph->mtime, my_strlen(ph->mtime));
                int arch_mtim = my_ctoi(tar_s->mtim_arr[index], my_strlen(tar_s->mtim_arr[index]));
                printf("file mtime : %i archi time :%i\n", file_mtim, arch_mtim);
                if (file_mtim > arch_mtim)
                {
                    printf("staaaaate :%i on i%i\n",getopt_ptr->state[index], index);
                    return 1;               
                }
            }
        index += 1;
    }
    return 0;
}
   // while(index < tar_s->nbr_str)
    // {
    //     if (my_strcmp(m_head->path_name, getopt_ptr->path_arr[index]) == 0)
    //     {
    //         return 1;
    //     }
    // }

