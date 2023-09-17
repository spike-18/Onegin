#include "lib.cpp"


#ifndef DEBUG
    #define RELEASE
#endif


int main(int argc, char* argv[])
{


            FILE* input     = NULL;
            FILE* output    = fopen("output.txt", "w");
    struct stat  file_info = {};


    if(checkargs(argc, argv) == HAS_FILENAME)
    {
        if( (input = fopen(argv[1], "r") ) == NULL)
        {
            printf("Cannot open file.\n");
            return OPEN_FILE_ERROR;
        }
    } else
        assert("No input file proceeded\n");



    fstat(fileno(input), &file_info);


    const size_t buf_len = file_info.st_size / sizeof(char);
    char* buf = (char*) calloc(buf_len + 1, sizeof(char));          // 1 byte if file dosn't end with '\n'


    size_t read_len = fread(buf, sizeof(char), buf_len, input);
    buf[read_len] = '\0';

    size_t rows_count = countrows(buf, read_len);

    Text_info* Text = (Text_info*) calloc(1, sizeof(Text_info));
    create_text(Text, rows_count);

    assert( !read_text(buf, read_len, Text) );


    Sort(Text->text, 0, Text->row_num-1, comparator);
    print_text_to_file(Text, output);

    fclose(input);
    fclose(output);
    free_text(Text);
    free(buf);

    return 0;
}

