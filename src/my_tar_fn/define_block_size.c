#include "../../include/main_header.h"

int define_block_size(int size_fd)
{
    if (size_fd < 512)
    {
        return size_fd; 
    }
    else
    {
        int size_block = 512;
        return size_block;
    }
}