#include "../../include/main_header.h"
#include <stdio.h>

void archive_to_file(my_getopt_t *getopt_ptr)
{
    int archive_fd = 0, fd = 0, size_fd = 0;
    printf("nbrstr : %i\n", getopt_ptr->nbr_str);
    ph_t* ph;
    
    archive_fd = open(getopt_ptr->path_arr[0], O_RDONLY);
    ph = malloc(sizeof(ph_t));
    
    do
    {
        read_archive(archive_fd, ph);
        write(1, ph, 500); // test check;
        fd = open(ph->name, O_RDWR | O_CREAT, 0644);
        size_fd = my_ctoi(ph->size, my_strlen(ph->size));
        size_fd = oct_to_dec(size_fd);
    }
    while (write_to_file(archive_fd, fd, size_fd) > 0); // NO !!!!!
    
    free(ph);
    close(archive_fd);
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