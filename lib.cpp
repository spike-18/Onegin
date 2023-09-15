#include "lib.hpp"



void create_text(Text_info *Text, const size_t row_num)
{
    Text->row_num = row_num;
    Text->text    = (char**) calloc(Text->row_num, sizeof(char*));
}


int read_text(char* buf, size_t buf_len, Text_info* Text, FILE* input)
{ 
    for (size_t i = 0; i < Text->row_num; i++)
    {
        fgets(buf, buf_len, input);
        Text->text[i] = (char*) calloc(strlen(buf),sizeof(char));

        strfill(Text->text[i], buf);
    }    
    return STABLE;
}


void print_text(Text_info *Text)
{    
    for (size_t i = 0; i < Text->row_num; i++)
        printf("%03d - %p - %s\n", i, &(Text->text[i]), Text->text[i]);
}


void free_text(Text_info *Text)
{
    for (size_t i = 0; i < Text->row_num; i++)
        free(Text->text[i]);
    free(Text->text);
}


int strfill(char* str1, char* str2)
{
    size_t i = 0;

    while(str2[i] != '\n')
    {
        assert( i >= strlen(str1) );
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
    
    return i;
}