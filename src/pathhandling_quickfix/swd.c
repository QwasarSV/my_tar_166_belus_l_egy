#include "../../include/main_header.h"
#include <stdio.h>

void swd(char* str, int pos) // set_working_directory
{
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    int len = my_strlen(str) - pos;
    char tmp_str[len + 1];
    printf("chdir %s\n", my_strncpy(tmp_str, str, len -1));
    chdir(tmp_str); // my_strncpy(tmp_str, getopt_ptr->path_arr[index], len -1)
}