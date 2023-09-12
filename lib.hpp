#include <stdio.h>
#include <stdlib.h>


enum ERROR_CODES {
    OPEN_FILE_ERROR = 1,
    READ_FILE_ERROR = 2,
    CORRECT         = 3
};

void  print_separately  ( const int data[], size_t sizeX, size_t sizeY );
void  print_united      ( const int data[] );
int   get_element       ( const int *data , size_t row_size, size_t posY, size_t posX );
