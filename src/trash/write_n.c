// #include "../../include/main_header.h"
// #include <stdio.h>

// void files_to_archive(my_getopt_t *getopt_ptr, node_t* m_head) 
// {
//     int fd = 0, write_fd = 0, write_archive_fd = 0, ref = 0, index = 0 ;
//     ref = index;
//     ph_t* ph;
//     printf("nbrstr : %i\n", getopt_ptr->nbr_str);
    
//     while (index < getopt_ptr->nbr_str -1)
//     {
//         index++;
//         ph = malloc(sizeof(ph_t));
//         ph = fill_ph(m_head->daughter_head, ph, getopt_ptr->path_arr[index]);
//         // printf("path : %s\n", getopt_ptr->path_arr[index]);
//         // printf("name : %s\n", ph->name);
//         // printf("size : %s\n", ph->size);
//         fd = open(getopt_ptr->path_arr[index], O_RDONLY);
//         write_fd = open(getopt_ptr->path_arr[index], O_RDONLY);
//         write_archive_fd = open(getopt_ptr->path_arr[ref], O_RDWR | O_APPEND | O_CREAT, 0644);
//         write_to_archive(fd, write_fd, write_archive_fd, ph);
//         free(ph);
//     }
// }





//TO RECODE DUMMY TEST

// void get_archive_info(my_getopt_t *getopt_ptr) 
// {
//     int fd = 0, index = 0 ;
//     printf("nbrstr : %i\n", getopt_ptr->nbr_str);
//     fd = open(getopt_ptr->path_arr[index], O_RDONLY);
    
//     while (index < getopt_ptr->nbr_str -1)
//     {
//         printf("path : %s\n", getopt_ptr->path_arr[index]);
//         //write_to_files(fd, write_fd, write_file_fd);
//         getopt_ptr->file_size[index] = read_file(fd);
//         index++;
//     }
//     close(fd);
// }

// void read_file(int fd, ph_t* ph)
// {   
//     int result = 0;
    
//     read(fd, ph, sizeof(ph_t));
//     result = my_ctoi(ph->size, my_strlen(ph->size));
//     printf("result : %i\n", result);
//     char burn[result + 512];
//     read(fd,burn,(result + 512));
    
//    // return ph;
// }



// void archive_to_file(my_getopt_t *getopt_ptr)
// {
//     int fd = 0, write_fd = 0, write_file_fd = 0, index = 0;
//     // char* tmp = malloc(sizeof(char)*2) ;
//     printf("nbrstr : %i\n", getopt_ptr->nbr_str);
//     ph_t* ph;
    
//     fd = open(getopt_ptr->path_arr[index], O_RDONLY);
//     write_fd = open(getopt_ptr->path_arr[index], O_RDONLY);

//     while (index < getopt_ptr->nbr_str -1)
//     {
//         index++;
//         ph = malloc(sizeof(ph_t));
//         read_file(write_fd, ph);
//         printf("path : %s\n", getopt_ptr->path_arr[index]);
        
//         //write_file_fd = open(their_itoa(index, tmp, 10), O_RDWR | O_APPEND | O_CREAT, 0644);
//         write_file_fd = open(ph->name, O_RDWR | O_CREAT, 0644);
        
//         write_to_file(fd, write_fd, write_file_fd, my_ctoi(ph->size, my_strlen(ph->size)));
//         free(ph);
//     }
//     close(fd);
//     close(write_fd);
// }

// TO RECODE DUMMY TEST

// void get_archive_info(my_getopt_t *getopt_ptr) 
// {
    // int fd = 0, index = 0 ;
    // printf("nbrstr : %i\n", getopt_ptr->nbr_str);
    // fd = open(getopt_ptr->path_arr[index], O_RDONLY);
    // 
    // while (index < getopt_ptr->nbr_str -1)
    // {
        // printf("path : %s\n", getopt_ptr->path_arr[index]);
        // write_to_files(fd, write_fd, write_file_fd);
        // getopt_ptr->file_size[index] = read_file(fd);
        // index++;
    // }
    // close(fd);
// }