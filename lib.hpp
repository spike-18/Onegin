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
    size_t row_num = NULL;
    size_t row_len = NULL;
    char*  text    = NULL;
} Text_info;



enum ERROR_CODES {
    STABLE          = 0,
    OPEN_FILE_ERROR = 1,
    READ_FILE_ERROR = 2,
    GET_SET_ERROR   = 3,
    FGETS_ERROR     = 4
};



int     read_text       (char* buf, Text_info* Text, FILE* input);
void    print_text      (Text_info *Text);
void    free_text       (Text_info *Text);
void    create_text     (Text_info *Text, const size_t row_num, FILE* input);
char*   strfill         (char* str1, char* str2);

    