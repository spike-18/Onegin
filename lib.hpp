#include <stdio.h>
#include <stdlib.h>
#include <math.h>


enum ERROR_CODES {
    CORRECT         = 0,
    OPEN_FILE_ERROR = 1,
    READ_FILE_ERROR = 2,
    GET_SET_ERROR   = 3  
};

void  print_separately  ( int data[], size_t sizeX, size_t sizeY );
void  print_united      ( int data[] );
int   get_set           ( char mode, int *data, size_t row_size, size_t posX, size_t posY, int new_val = 0 );