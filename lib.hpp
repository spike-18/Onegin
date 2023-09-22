#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
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
    ONE_ELEM    = 1,
    TWO_ELEM    = 2,
    THREE_ELEM  = 3
};


enum ERROR_CODES {
    MEOW                = 0,
    OPEN_FILE_ERROR     = 1,
    READ_FILE_ERROR     = 2,
    GET_SET_ERROR       = 3,
    FGETS_ERROR         = 4,
    CHECK_PARAM_ERROR   = 5,
    NO_FILENAME         = 6
};


size_t  countrows           (char* buf, size_t buf_len);
int     read_text           (char* buf, size_t read_len, Text_info* Text);
int     checkargs           (int argc, char* argv[]);
int     str_frw_comp        (void* a, void* b);
int     int_comp            (void* a, void* b);
int     isignored           (char c);
void    print_text          (Text_info *Text);
void    free_text           (Text_info *Text);
void    print_text_to_file  (Text_info *Text, FILE* output);
void    create_text         (Text_info *Text, const size_t row_num);
void    sort_two            (char* left, char* right, size_t el_size, int (*comp) (const void* a, const void* b));
void    sort_three          (char* left, char* right, size_t el_size, int (*comp) (const void* a, const void* b));
void    Sort                (void* data, size_t len, size_t el_size, int (*comp) (const void* a, const void* b));
void*   partition           (void* left, void* right, size_t el_size, int (*comp) (const void* a, const void* b));
void    swap                (void* a, void* b, size_t el_size);

#ifdef DEBUG
void    print_data          (int** lb, int** rb, int** left, int** right, int** piv);
void    test_sort           (int** data, int data_size);
#endif
