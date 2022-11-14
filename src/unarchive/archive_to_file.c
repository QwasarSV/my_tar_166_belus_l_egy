#include "../../include/main_header.h"
#include <stdio.h>

void archive_to_file(my_getopt_t *getopt_ptr)
{
    int fd = 0, write_fd = 0, write_file_fd = 0, index = 0, result = 0;
    // char* tmp = malloc(sizeof(char)*2);
    printf("nbrstr : %i\n", getopt_ptr->nbr_str);
    ph_t* ph;
    
    fd = open(getopt_ptr->path_arr[index], O_RDONLY);
    write_fd = open(getopt_ptr->path_arr[index], O_RDONLY);
    ph = malloc(sizeof(ph_t));
    
    do
    {
        read_archive(write_fd, ph);
        write(1, ph, 500); // test check;
        write_file_fd = open(ph->name, O_RDWR | O_CREAT, 0644);
    }
    while (write_to_file(fd, write_fd, write_file_fd, oct_to_dec(my_ctoi(ph->size, my_strlen(ph->size)))) > 0); // NO !!!!!
    
    free(ph); 
    close(fd);
    close(write_fd);
}

//while ((initial_size = read(write_fd, file_RnW_buffer, size_block)))

//while (write_to_file(fd, write_fd, write_file_fd, oct_to_dec(my_ctoi(ph->size, my_strlen(ph->size)))) > 0);

// {
    // int fd = 0, write_fd = 0, write_file_fd = 0, index = 0;
    // char* tmp = malloc(sizeof(char)*2);
    // printf("nbrstr : %i\n", getopt_ptr->nbr_str);
    // ph_t* ph;
    // 
    // fd = open(getopt_ptr->path_arr[index], O_RDONLY);
    // write_fd = open(getopt_ptr->path_arr[index], O_RDONLY);
// 
    // while (index < getopt_ptr->nbr_str -1)
    // {
        // index++;
        // ph = malloc(sizeof(ph_t));
        // read_archive(write_fd, ph);
        // test_archive(write_fd, ph);
        // write(1, ph, 500);
        // printf("\n path : %s\n", getopt_ptr->path_arr[index]);
        // 
        // write_file_fd = open(their_itoa(index, tmp, 10), O_RDWR | O_APPEND | O_CREAT, 0644);
        // write_file_fd = open(ph->name, O_RDWR | O_CREAT, 0644);
        // 
        // write_to_file(fd, write_fd, write_file_fd, oct_to_dec(my_ctoi(ph->size, my_strlen(ph->size))));
        // free(ph);
    // }
    // close(fd);
    // close(write_fd);
// }