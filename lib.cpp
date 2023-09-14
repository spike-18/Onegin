#include "lib.hpp"


int read_text(size_t row_num, size_t row_len, char *text, FILE *input)
{ 
    for(size_t i = 0; i < row_num; i++)     
        fgets(text+i*row_len, row_len, input);        
    return STABLE;
}


void print_text(size_t row_num, size_t row_len, char *text)
{    
    for (size_t i = 0; i < row_num; i++)
        printf("%s", text + i*row_len);
}

