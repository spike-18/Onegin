#include "lib.hpp"


int read_text(size_t row_len, char *text, FILE *input)
{
    size_t row_num = sizeof(text)/row_len;    
    for(size_t i = 0; i < row_num; i++)
        fgets(text + i*row_num, row_len, input);
    return CORRECT;
}


void print_text(size_t row_len, char *text)
{
    size_t row_num = sizeof(text)/row_len;    
    for (size_t i = 0; i < row_num; i++)
        for(size_t j = 0; j < row_len; j++)
            printf("%s", *(text + i*row_num + j));
}

