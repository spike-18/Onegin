#include "lib.cpp"


#ifndef DEBUG
    #define RELEASE
#endif


int main(int argc, const char *argv[])
{   
    
    const size_t row_num = 200;
    const size_t row_len = 100;
    char *text = (char*) calloc(row_len*row_num, sizeof(char));


    FILE *input = NULL;

    if( (input = fopen("hamlet.txt", "r") ) == NULL) {
        printf("Cannot open file.\n");
        return OPEN_FILE_ERROR;
    }

    //struct stat file_info = {};
    //fstat(fileno(finput), &file_info);

    read_text(row_len, text, input);
    print_text(row_len, text);

    fclose(input);
    free(text);

    return 0;
} 