#include "lib.hpp"


void print_separately (const int data[], size_t sizeX, size_t sizeY)
{
    printf("\n");
    for(size_t i = 0; i < sizeX; i++)
    {
        for(size_t j = 0; j < sizeY; j++)
            printf("%02d ", get_element(data,sizeY,i,j));
        printf("\n");
    }
}


void print_united (const int data[])
{
    print_separately(data+2, data[0], data[1]);
}


int get_element(const int data[], size_t row_size, size_t posX, size_t posY)
{
    return *(data + row_size*posX + posY); 
}