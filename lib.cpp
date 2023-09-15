#include "lib.hpp"


int read_text(char *buf, Text_info *Text, FILE *input)
{ 
    for (size_t i = 0; i < Text->row_num; i++)
    {
        if(fgets(buf, sizeof(buf), input) == NULL)
            return FGETS_ERROR;
        
        Text->text[i] = (char) calloc(strlen(buf),sizeof(char));
        
        strfill()

    }
    
    
    return STABLE;
}




void print_text(Text_info *Text)
{    
    for (size_t i = 0; i < Text->row_num; i++)
        printf("%s", Text->text[i]);
}




void create_text(Text_info *Text, const size_t row_num, FILE *input)
{
    Text->row_num = row_num;
    Text->text    = (char*) calloc(Text->row_num, sizeof(char*));
}




void free_text(Text_info *Text)
{
    for (size_t i = 0; i < Text->row_num; i++)
        free(&(Text->text[i]));
    free(&(Text->text));
}



char* strfill()
{
    return 
}