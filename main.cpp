#include "lib.cpp"


#ifndef DEBUG
    #define RELEASE
#endif


int main()
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
    create_text(Text, 100);

    //printf("%d\n", sizeof(Text->text));

    const size_t buf_len = 200;
    char buf[buf_len] = {};    
    
    assert( !read_text(buf, buf_len, Text, input) );

    print_text(Text);

    fclose(input);
    free_text(Text);

    return 0;
} 