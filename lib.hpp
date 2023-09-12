#include <stdio.h>
#include <stdlib.h>


enum ERROR_CODES {
    OPEN_FILE_ERROR = 1,
    READ_FILE_ERROR = 2,
    CORRECT         = 3
};

void print_arr_1 (const int data[], size_t sizeX, size_t sizeY);
