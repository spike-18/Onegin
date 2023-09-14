#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <sys\stat.h>
#include <string.h>


enum ERROR_CODES {
    CORRECT         = 0,
    OPEN_FILE_ERROR = 1,
    READ_FILE_ERROR = 2,
    GET_SET_ERROR   = 3  
};

int     read_text           (size_t row_len, char *text, FILE *input);
void    print_text          (size_t row_len, char *text);
