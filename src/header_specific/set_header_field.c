#include <stddef.h>
#include "../../include/main_header.h"
// void* p ; generic pointer type. can be converted to any type without "explicit" cast,  // size_t is for array indexing and loop counting
// generic pointers cannot be dereferenced, must convert to a pointer before using it.

void set_header_field(void *generic_ptr, char ch, size_t size) 
{
    char *arr = generic_ptr;  
    int index = 0;

    while ( index < size -1 )
    {
        arr[index] = ch;
        index += 1;
    }

    arr[index] = '\0';
}