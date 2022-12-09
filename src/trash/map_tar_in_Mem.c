#include "../../include/main_header.h"
//#include "../../include/my_stdio.h" 
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>

// ALTERNATE METHOD(ABANDONED) : MEM REQUIREMENT TOO HIGH OR IS REDONDANT TO CURRENT CODE

void map_tar(node_t* head)
{
    node_t* tmp = head;

    char *FIM;
    int len;
    int size_fd = 0;
    while (tmp != NULL)
    {
        
        len = my_strlen(tmp->path_name);
        if (tmp->path_name != 0 && my_strcmp(&tmp->path_name[len-4], ".tar") == 0)
        {
            printf("path_name :%s \n", tmp->path_name);
            int fd = open(tmp->path_name, O_RDWR , 0644);
            
            size_fd = tmp->st.st_size;
            printf("sizeFd : %i\n",size_fd);
            
            FIM = mmap(NULL, size_fd, PROT_READ, MAP_SHARED, fd, 0);
            printf("FIM%s\n", FIM);
            close(fd);
        }
        tmp = tmp->next;
    }
    if (FIM != MAP_FAILED)
    {
        
//        check_file_arr(getopt_ptr, FIM);
        munmap(FIM, size_fd);
    }

}