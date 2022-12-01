#include "../../include/main_header.h"

void store_filenames(my_tar_struct* tar_s, char* filename, char* mtim, int index)
{
    tar_s->str_arr[index] = malloc(sizeof(char)* my_strlen(filename) +1);
    my_strcpy(tar_s->str_arr[index], filename);

    tar_s->mtim_arr[index] = malloc(sizeof(char)* my_strlen(filename) +1);
    my_strcpy(tar_s->mtim_arr[index], mtim);
}