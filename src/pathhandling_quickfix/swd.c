#include "../../include/main_header.h"
#include <stdio.h>

void swd(char* str, int pos) // set_working_directory
{
    //char cwd[PATH_MAX];
    //getcwd(cwd, sizeof(cwd));
    //int len = my_strlen(str) - 1 - pos;
    //printf("len chdir %i \n", len);
    char tmp_str[pos +1];
    my_strncpy(tmp_str, str, pos);
    //printf("chdir %s\n",tmp_str );
    chdir(tmp_str); // my_strncpy(tmp_str, getopt_ptr->path_arr[index], len -1)
}