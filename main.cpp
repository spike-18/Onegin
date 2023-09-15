#include "lib.cpp"


#ifndef DEBUG
    #define RELEASE
#endif


int main(int argc, const char *argv[])
{   

           FILE *input     = NULL;
    struct stat  file_info = {};


    if( (input = fopen("hamlet.txt", "r") ) == NULL)
    {
        printf("Cannot open file.\n");
        return OPEN_FILE_ERROR;
    }


    fstat(fileno(input), &file_info);



    Text_info* Text = (Text_info*) calloc(1, sizeof(Text_info));    
    create_text(Text, 100, input);


    char buf[1024] = {};    
    
    assert( !read_text(buf, Text, input) );

    print_text(Text);

    fclose(input);
    free_text(Text);

    return 0;
} 