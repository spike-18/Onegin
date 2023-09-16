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

    //printf("%d\n", sizeof(Text->text));

    const size_t buf_len = file_info.st_size / sizeof(char);
    char* buf = (char*) calloc(buf_len + 1, sizeof(char));          // 1 byte if file dosn't end with '\n'


    size_t read_len = fread(buf, sizeof(char), buf_len, input);
    buf[read_len] = '\0';
    //printf("File: %d\n", buf_len);
    //printf("Read: %d\n", read_len);

    size_t rows_count = countrows(buf, read_len);
    //printf("%ld\n", rows_count);

    Text_info* Text = (Text_info*) calloc(1, sizeof(Text_info));
    create_text(Text, rows_count);

    assert( !read_text(buf, read_len, Text) );

    //printf("%s\n", buf);
    //print_text(Text);



    /*
    const int data_size = 20;
    int** data = (int**) calloc(data_size, sizeof(int*));

    srand(time(NULL));

    for (int i = 0; i < data_size; i++)
    {
        data[i] = (int*) calloc(1, sizeof(int));
        *data[i] = rand() % data_size;
    }
    */

    Sort(Text->text, 0, Text->row_num-1, comparator);
    print_text(Text);

    fclose(input);
    free_text(Text);
    free(buf);

    return 0;
}

