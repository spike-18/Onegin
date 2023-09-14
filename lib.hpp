#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>


#ifdef _WIN32
    #include <sys\stat.h>
#else
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h> 
#endif



enum ERROR_CODES {
    STABLE          = 0,
    OPEN_FILE_ERROR = 1,
    READ_FILE_ERROR = 2,
    GET_SET_ERROR   = 3  
};



int     read_text       (size_t row_num, size_t row_len, char *text, FILE *input);
void    print_text      (size_t row_num, size_t row_len, char *text);
    