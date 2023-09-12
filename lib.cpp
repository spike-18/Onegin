#include "lib.hpp"



void print_arr_1 (const int data[], size_t sizeX, size_t sizeY)
{
    printf("\n");
    for(size_t j = 0; j < sizeX; j++)
    {
        for(size_t i = 0; i < sizeY; i++)
            printf("%02d ", *(data + j*sizeX + i));
        printf("\n");
    }
}

void print_arr_2 (const int data[])
{
    size_t sizeX = data[0];
    size_t sizeY = data[1];
    for(size_t j = 0; j < sizeX; j++)
    {
        for(size_t i = 0; i < sizeY; i++)
            printf("%02d ", *(data + j*sizeX + i));
        printf("\n");
    }
}