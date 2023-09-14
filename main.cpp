#include "lib.cpp"


#ifndef DEBUG
    #define RELEASE
#endif


int main(int argc, const char *argv[])
{   

    FILE *input = NULL;

    if( (input = fopen("hamlet.txt", "r") ) == NULL)
    {
        printf("Cannot open file.\n");
        return OPEN_FILE_ERROR;
    }

    struct stat file_info = {};
    
    fstat(fileno(input), &file_info);


    const size_t row_len = 100;
    const size_t row_num = (size_t) file_info.st_size;              // so that there was always enough lines to fit any file.
    char *text = (char*) calloc(row_len*row_num, sizeof(char));


    read_text (row_num, row_len, text, input);
    print_text(row_num, row_len, text);

    fclose(input);
    free  (text);

    return 0;
} 