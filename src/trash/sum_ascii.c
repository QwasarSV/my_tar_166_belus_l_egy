#include "../../include/main_header.h"

int sum_ascii(char* str)
{
    int index = 0;
    int sum = 0;
    while (str[index] != '\0')
    {
        sum += base_converter(str[index], 8);
        index += 1;
    }
    return sum;
}

