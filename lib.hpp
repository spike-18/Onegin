#include <stdio.h>
#include <stdlib.h>
#include <math.h>


enum ERROR_CODES {
    CORRECT         = 0,
    OPEN_FILE_ERROR = 1,
    READ_FILE_ERROR = 2,
    GET_SET_ERROR   = 3  
};

void  print_separately  (const int data[], size_t sizeX, size_t sizeY );
void  print_united      (const int data[] );
int   getter            (const int data[], size_t row_size, size_t posX, size_t posY);
int   setter            (int data[], size_t row_size, size_t posX, size_t posY, int new_val);
int   get_set           ( char mode, int *data, size_t row_size, size_t posX, size_t posY, int new_val = 0 );