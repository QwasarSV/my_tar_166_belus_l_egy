#include "../../include/main_header.h"

//int pos = path_to_name(getopt_ptr->path_arr[index]);
int path_to_name(char* str)
{
    int len = 0; 
    len =  my_strlen(str);

    while (str[len] != '/' && len > 0)
    {
        len -= 1;
    }
    return len;
}

