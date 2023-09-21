#include "lib.cpp"


#ifndef DEBUG
    #define RELEASE
#endif


int main(int argc, char* argv[])
{

    // Preparing files

    FILE* input  = NULL;
    FILE* output = fopen("output.txt", "w");

    if (checkargs(argc, argv) == NO_FILENAME)
        assert("No input file proceeded\n");

    if (( input = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open file.\n");
        return OPEN_FILE_ERROR;
    }


    // Initializing buffer,

    struct stat file_info = {};
    fstat( fileno(input), &file_info );

    const size_t buf_len = file_info.st_size / sizeof(char);
          char*  buf     = (char*) calloc(buf_len + 1, sizeof(char));          // 1 byte if file dosn't end with '\n'


    // Reading file into buffer

    size_t     read_len   = fread(buf, sizeof(char), buf_len, input);
    size_t     rows_count = countrows(buf, read_len);

    Text_info* Text       = (Text_info*) calloc(1, sizeof(Text_info));
    create_text(Text, rows_count);

    assert( !read_text(buf, read_len, Text) );


    // Sorting data

    const int data_size = 10000000;
    int* data = (int*) calloc(data_size, sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < data_size; i++)
        data[i] = rand() % data_size;


    Sort(data, data_size, sizeof(int), (int (*) (const void* a, const void* b)) int_comp);

    test_sort(data, data_size);

    // Printing sorted data

    // print_text_to_file(Text, output);

    //printf("%d %d %d\n", data[0], data[2], data[3]);
    //void* a = data;
    //printf("%d %d\n", (char*)&data[3]-(char*)&data[0], *(int*)(1+2*sizeof(int) + (int*)a));

    // Clearing memory

    fclose(input);
    fclose(output);
    free_text(Text);
    free(buf);

    return MEOW;
}

