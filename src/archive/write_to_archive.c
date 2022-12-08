#include "../../include/main_header.h"
#include <stdio.h>

int write_to_archive(int fd, int archive_fd, ph_t* ph)
{
    int block_size = 0, size_fd = 0, initial_size = 0, byte_count = 0;

    size_fd = my_ctoi(ph->size, my_strlen(ph->size));
    size_fd = oct_to_dec(size_fd);
    block_size = define_block_size(size_fd);
    char buff[size_fd];
    
    byte_count += write_header(archive_fd, buff, ph);

    if (ph->typeflag != '5')
    {
        byte_count += write_chunk(fd, archive_fd, buff, block_size);
    }
    
    if (size_fd % SIZE != 0 ) // temp check to remove
    {
        byte_count += padding_null(archive_fd, size_fd%512);
    }
    // else 
    // {
    //     byte_count += padding_null(archive_fd, 0);
    // }

    close(fd);
    return byte_count;
}

//replaced by write_header
    // write(archive_fd, &(*ph), sizeof(ph_t));
    // char buff[size_fd];
    // char burn[12] = {'\0'};
    // write(archive_fd, burn, 12);
    // block_count += 1;

//replaced by write_chunk
    // while ((initial_size = read(fd, buff, size_block)))
    // {
    //     write(archive_fd, buff, initial_size);
    //     block_count += 1;
    // }