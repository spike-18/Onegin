#include "lib.hpp"


void print_separately (const int data[], size_t sizeX, size_t sizeY)
{
    printf("\n");
    for(size_t i = 0; i < sizeX; i++)
    {
        for(size_t j = 0; j < sizeY; j++)
            printf("%02d ", getter(data, sizeY, i, j));
        printf("\n");
    }
}


void print_united (const int data[])
{
    print_separately(data+2, data[0], data[1]);
}


int getter(const int data[], size_t row_size, size_t posX, size_t posY)
{
    return *(data + row_size*posX + posY); 
}

int setter(int data[], size_t row_size, size_t posX, size_t posY, int new_val)
{
    int old_val = *(data + row_size*posX + posY);
    *(data + row_size*posX + posY) = new_val;
    return old_val;
}

int get_set(char mode, int data[], size_t row_size, size_t posX, size_t posY, int new_val)
{
    if(mode == 'g')
        return *(data + row_size*posX + posY); 
    
    else if(mode == 's')
    {
        int old_val = *(data + row_size*posX + posY);
        *(data + row_size*posX + posY) = new_val;
        return old_val;
    }
    else
    {
        printf("Incorrect arguments in get_set\n");
        return GET_SET_ERROR;
    }
}