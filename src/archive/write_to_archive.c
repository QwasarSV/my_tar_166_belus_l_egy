#include "../../include/main_header.h"
#include <stdio.h>

int write_to_archive(int fd, int archive_fd, ph_t* ph)
{
    int size_block = 0, size_fd = 0, initial_size = 0, block_count = 0;

    size_fd = my_ctoi(ph->size, my_strlen(ph->size));
    size_fd = oct_to_dec(size_fd);
    size_block = define_block_size(size_fd);

    write(archive_fd, &(*ph), sizeof(ph_t));
    char buff[size_fd];
    char burn[12] = {'\0'};
    write(archive_fd, burn, 12);
    block_count += 1;

    while ((initial_size = read(fd, buff, size_block)))
    {
        write(archive_fd, buff, initial_size);
        block_count += 1;
    }

    if (size_fd%SIZE != 0 ) // temp check to remove
    {
        padding_null(archive_fd, size_fd%512);
    }

    close(fd);
    return block_count;
}