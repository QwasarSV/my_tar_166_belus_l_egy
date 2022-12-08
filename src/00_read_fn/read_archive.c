#include "../../include/main_header.h"
#include <stdio.h>

void read_archive(int archive_fd, my_getopt_t* getopt_ptr)
{
    int fd = 0, size_file = 0;
    ph_t* ph;
    do
    {
        ph = malloc(sizeof(ph_t));
        read_header(archive_fd, ph);
        fd = open(ph->name, getopt_ptr->oflag, 0644);
        size_file = my_ctoi(ph->size, my_strlen(ph->size));
        size_file = oct_to_dec(size_file);
        free(ph);
    }
    while (write_to_file(archive_fd, fd, size_file) > 0);
}

int read_archive02(int fd, my_getopt_t* getopt_ptr)
{
    int byte_count = 0, size_file = 0, result = 0;
    ph_t* ph;

    do
    {

        ph = malloc(sizeof(ph_t));
        byte_count += read_header(fd, ph);
        printf("byte_count - header :%i\n",SIZE);
        size_file = my_ctoi(ph->size, my_strlen(ph->size));
        size_file = oct_to_dec(size_file);
        free(ph);
        result = read_to_pos(fd, size_file, getopt_ptr);
        //printf("result :%i\n",result);
        byte_count += result ; // + (SIZE - (size_file % SIZE));
    }
    while (result > 0);
    
    return byte_count;
}

int read_archive03(int fd, my_getopt_t* getopt_ptr, my_tar_struct* tar_s)
{
    int byte_count = 0, file_size = 0;
    ph_t* ph;
    char *filename = malloc(sizeof(char)*100);
    do
    {
        ph = malloc(sizeof(ph_t));
        read_header(fd, ph);
        file_size = my_ctoi(ph->size, my_strlen(ph->size));
        file_size = oct_to_dec(file_size);
        tar_s->tar_map[tar_s->index] = 1;
        tar_s->index += 1;
        tar_map_file(file_size, tar_s);
        my_strcpy(filename, ph->name);
        tar_s->nbr_str += 1;
        
        byte_count += file_size + file_size % SIZE + SIZE;
        free(ph);
    }
    while (filename[0] != '\0' && map_archive(fd, file_size, tar_s) > 0);
    
    int index = 0;
    printf("\ntar_map :");
    while(index < tar_s->index)
    {
        printf("%i-",tar_s->tar_map[index]);
        index++;
    }
    printf("\n");
    tar_s->tar_state += 1;

    free(filename);

    return byte_count;
}