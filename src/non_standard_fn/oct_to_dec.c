#include "../../include/main_header.h"

int my_iterative_pow(int value, int power)
{
    int index = 0;
    if (power == 0) 
    {
        return 1;
    }
    
    int result = value;
    while (index < power - 1)
    {
        result *= value;
        index++;
    }

    return result;
}

//long long oct_to_dec(long long int value)
int oct_to_dec(int value)
{

    int dec = 0;
    int base = 1;
    int temp = value;

    while (temp)
    {
        int lastdigit = temp % 10;
        temp = temp / 10;

        dec += lastdigit * base;

        base = base * 8;
    }

return dec;

    // int x = 0;
    // int ans = 0;
    // int y = 0;
    
    // while (value > 0)
    // {
    //     y = value % 10;
    //     value /= 10;
    //     ans += y * my_iterative_pow(8, x);
    //     ++x;
    // }

    // return ans;

    // long int dec = 0;
    // int index = 0;
    // while (value != 0)
    // {   //printf("%i",my_iterative_pow(8, index));
    //     dec = dec + (value % 10) * my_iterative_pow(8, index++);
    //     value = value / 10; 
    // }

    // return dec;
    // int result = 0, index = 0;

    // while (value != 0) {
    //     result += (value % 10) * my_iterative_pow(8, index);
    //     ++index;
    //     value /= 10;
    // }
    // return result;
}