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


typedef struct
{
    size_t row_num = 0;
    size_t row_len = 0;
    char** text    = NULL;
} Text_info;



enum ERROR_CODES {
    STABLE              = 0,
    OPEN_FILE_ERROR     = 1,
    READ_FILE_ERROR     = 2,
    GET_SET_ERROR       = 3,
    FGETS_ERROR         = 4,
    CHECK_PARAM_ERROR   = 5
};



int     read_text       (char* buf, size_t read_len, Text_info* Text);
void    print_text      (Text_info *Text);
void    free_text       (Text_info *Text);
void    create_text     (Text_info *Text, const size_t row_num);
size_t  countrows       (char* buf, size_t buf_len);
    