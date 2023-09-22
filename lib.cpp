#include "qsort.cpp"


void create_text(Text_info *Text, const size_t row_num)
{
    Text->row_num = row_num;
    Text->text    = (char**) calloc(Text->row_num, sizeof(char*));
}


int read_text(char* buf, size_t read_len, Text_info* Text)
{
    size_t line = 0;
    size_t    i = 0;

    while (isignored(buf[i]))
        i++;

    Text->text[0] = buf + i;

    for ( ; i < read_len; i++)
        if (buf[i] == '\n')
        {
            buf[i] = '\0';
            line++;
            i++;

            for ( ; isignored(buf[i]); i++)
                if (buf[i] == '\n')
                    Text->row_num--;

            Text->text[line] = buf + i;
        }

    return MEOW;
}



void print_text(Text_info *Text)
{
    for (size_t line = 0; line < Text->row_num; line++)
        printf("%03d - %p| %s\n", (int) line, Text->text[line], Text->text[line]);
}


void print_text_to_file(Text_info *Text, FILE* output)
{
    for (size_t line = 0; line < Text->row_num; line++)
        fprintf(output, "%03d - %p| %s\n", (int) line, Text->text[line], Text->text[line]);
}


void free_text(Text_info *Text)
{
    free(Text->text);
    free(Text);
}


size_t countrows(char* buf, size_t buf_len)
{
    size_t num = 0;
    for (size_t i = 0; i < buf_len; i++)
        if (buf[i] == '\n')
            num++;

    return num;
}


int checkargs(int argc, char* argv[])
{
    if (argc >= 2 && argv[1])
        return MEOW;
    else
        return NO_FILENAME;
}


int isignored(char c)
{
    switch (c)
    {
        case ' ':       case '0':
        case '\"':      case '1':
        case '\'':      case '2':
        case '(':       case '3':
        case '.':       case '4':
        case ')':       case '5':
        case ',':       case '6':
        case '_':       case '7':
        case '-':       case '8':
        case '[':       case '9':
        case ']':
        case '\n':
            return 1;

        default:
            return 0;
    }
}
