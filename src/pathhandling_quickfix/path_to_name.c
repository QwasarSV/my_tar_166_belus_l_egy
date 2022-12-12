#include "../../include/main_header.h"
#include <stdio.h>
//int pos = path_to_name(getopt_ptr->path_arr[index]);
int path_to_name(char* str)
{
    int len = 0, count = 0; 
    len =  my_strlen(str) -1;
    //printf("\nlen %i\n", len);
    while (str[len] != '/' && len > 0)
    {
      //  printf("%c-",str[len]);
        len -= 1;
        count += 1;
    }
    //len +=2;
    //printf("\nlen %i count = %i\n", len, count);
    return len;
}

