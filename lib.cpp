#include "qsort.cpp"



void create_text(Text_info *Text, const size_t row_num)
{
    Text->row_num = row_num;
    Text->text    = (char**) calloc(Text->row_num, sizeof(char*));
}



int read_text(char* buf, size_t read_len, Text_info* Text)
{

    Text->text[0] = buf;
    size_t line = 0;

    for(size_t i = 0; i < read_len; i++)
    {
        if(buf[i] == '\n')
        {
            line++;
            buf[i] = '\0';
            Text->text[line] = buf + i + 1;
        }
    }

    return STABLE;
}



void print_text(Text_info *Text)
{
    for (size_t line = 0; line < Text->row_num; line++)
        printf("%03d - %p| %s\n", (int) line, &(Text->text[line]), Text->text[line]);
}

void print_text_to_file(Text_info *Text, FILE* output)
{
    for (size_t line = 0; line < Text->row_num; line++)
        fprintf(output, "%03d - %p| %s\n", (int) line, &(Text->text[line]), Text->text[line]);
}



void free_text(Text_info *Text)
{
    free(Text->text);
    free(Text);
}



size_t countrows(char* buf, size_t buf_len)
{
    size_t num = 1;
    for(size_t i = 0; i < buf_len; i++)
        if(buf[i] == '\n')
        {
            num++;
        }

    return num;
}


int checkargs(int argc, char* argv[])
{
    if(argc >= 2 && argv[1])
        return HAS_FILENAME;
    else
        return NO_FILENAME;
}
