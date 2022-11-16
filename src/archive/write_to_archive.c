#include "../../include/main_header.h"
#include <stdio.h>

int write_to_archive(int fd, int archive_fd, ph_t* ph)
{
    int size_block = 0, size_fd = 0, initial_size = 0, count_block = 0;
    size_fd = my_ctoi(ph->size, my_strlen(ph->size));
    size_fd = oct_to_dec(size_fd);
    size_block = define_block_size(size_fd);

    write(archive_fd, &(*ph), sizeof(ph_t));
    char file_RnW_buffer[size_fd];
    char buff[12] = {'\0'};
    write(archive_fd, buff, 12);
    count_block += 1;

    while ((initial_size = read(fd, file_RnW_buffer, size_block)))
    {
        write(archive_fd, file_RnW_buffer, initial_size);
        count_block += 1;
    }

    if (size_fd%SIZE != 0) // temp check to remove
    {
        padding_null(archive_fd, size_fd%512);
    }

    close(fd);
    return count_block;
}

    // printf("ph size :   %s\n", ph->size);
    // printf("block_size: %i\n",size_block);
    // printf("size_fd_dec:%i\n",size_fd);
// 
// {
//     //(void)ph;
//     int size_block = 0, size_fd = 0, initial_size = 0, count_block = 1;
//     size_fd = oct_to_dec(my_ctoi(ph->size, my_strlen(ph->size)));

//     size_block = define_block_size(size_fd);

//         printf("ph name : %s\n", ph->name);
//         ;
//     write(write_archive_fd, &(*ph), sizeof(ph_t));
    
//     char file_RnW_buffer[size_fd];
    
//     char buff[12] = {'\0'};
    
//     write(write_archive_fd, buff, 12);

//     while ((initial_size = read(write_fd, file_RnW_buffer, size_block)))
//     {
//         write(write_archive_fd, file_RnW_buffer, size_block);
//         //count_block += 1;
//     }

//     padding_null(write_archive_fd, size_block);
//         count_block += 1;
//     close(fd);
//     close(write_fd);
//     return count_block;
// }

// //(void)ph;
//     (void)fd;
//     int size_block = 0, initial_size = 0, ph_size = 0; //size_fd = 0,

//     ph_size = my_ctoi(ph->size, my_strlen(ph->size));
//     //write_struct(write_archive_fd, ph);
    
//     write(write_archive_fd, &(*ph), sizeof(ph_t));
    
//         printf("ph name : %s\n", ph->name);
//         printf("ph size : %s\n", ph->size);
    
//     if(ph_size < 512)
//     {
//         size_block = ph_size; 
//     }
//     else
//     {
//         size_block = 512;
//     }

//     char buff[12] = {'\0'};
//     write(write_archive_fd, buff, 12);
   
//     char file_RnW_buffer[size_block];
    
//     //while ((initial_size = read(write_fd, file_RnW_buffer, size_block)))
//     //{
//         write(write_archive_fd, file_RnW_buffer, size_block);
//     //}

//     // printf("size fd :%i\n",size_fd);
    
//     padding_null(write_archive_fd, size_block); 
//     ph_size = 0;
//     close(fd);
//     close(write_fd);
//     close(write_archive_fd);





    //     //char file_RDON_buffer[SIZE];
    // while ((size_block = read(fd, file_RDON_buffer, SIZE)))
    // {
    //     size_fd = size_fd + size_block;
    // }