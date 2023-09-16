#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <time.h>


#ifdef _WIN32
    #include <sys\stat.h>
#else
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
#endif


#define STD "\033[1;0m"
#define BLK "\u001b[30;1m"
#define RED "\u001b[31;1m"
#define GRN "\u001b[32;1m"
#define YEL "\u001b[33;1m"
#define BLU "\u001b[34;1m"
#define MAG "\u001b[35;1m"
#define CYN "\u001b[36;1m"
#define WHT "\u001b[37;1m"


typedef struct
{
    size_t row_num = 0;
    size_t row_len = 0;
    char** text    = NULL;
} Text_info;



enum NUM_OF_ELEMENTS {
    ONE_ELEM        = 0,
    TWO_ELEM        = 1,
    THREE_ELEM      = 2
};



enum ERROR_CODES {
    STABLE              = 0,
    OPEN_FILE_ERROR     = 1,
    READ_FILE_ERROR     = 2,
    GET_SET_ERROR       = 3,
    FGETS_ERROR         = 4,
    CHECK_PARAM_ERROR   = 5
};



size_t  countrows       (char* buf, size_t buf_len);
int     read_text       (char* buf, size_t read_len, Text_info* Text);
void    print_text      (Text_info *Text);
void    free_text       (Text_info *Text);
void    create_text     (Text_info *Text, const size_t row_num);
void    Sort            (int* data, int left, int right);
int     partition       (int* data, int left, int right);
void    sort_two        (int* data, int left, int right);
void    sort_three      (int* data, int left, int right);
void    swap            (int* data, int left, int right);
void    print_data      (int* data, int lb, int rb, int left, int right, int piv);
void    test_sort       (int* data, int data_size);
