// #include "../../include/main_header.h"
// #include <stdio.h>
// void write_to_archive(int fd, int write_fd, int write_archive_fd, ph_t* ph)
// { (void)ph;
//     int size_block = 0, size_fd = 0, initial_size = 0;
//     char file_RDON_buffer[SIZE];

//     while ((size_block = read(fd, file_RDON_buffer, SIZE)))
//     {
//         size_fd = size_fd + size_block;
//     }

//     char file_RnW_buffer[size_fd];
//             printf("name : %s\n", ph->name);
//         printf("size : %s\n", ph->size);
//     //write_struct(write_archive_fd, ph);
//     write(write_archive_fd, ph, sizeof(ph_t));

//     while ((initial_size = read(write_fd, file_RnW_buffer, size_fd)))
//     {
//         write(write_archive_fd, file_RnW_buffer, size_fd);
//     }
    
//     padding_null(write_archive_fd); 
    
//     close(fd);
//     close(write_fd);
//     close(write_archive_fd);
// }



// TO RECODE DUMMY TEST


// int read_file(int fd)
// {   
//     ph_t ph;
//     int result = 0;
//     char file_buffer[9999];
//     read(fd, &ph, sizeof(ph_t));
//     result = my_ctoi(ph.size, my_strlen(ph.size));
//     printf("result : %i\n", result);
//     read(fd,file_buffer,(result + 512));
//     return result;
// }

// void write_to_file(int fd, int write_fd, int write_file_fd, int file_size)
// {
//     (void)write_fd;
//     char burn01[500];
//     char burn02[512];
//     read(fd, burn01, 500);
//     char file_RnW_buffer[file_size];   
//     read(fd, file_RnW_buffer, file_size);
//     write(write_file_fd, file_RnW_buffer, file_size);
//     read(fd, burn02, 512);
//     close(write_file_fd);
// }