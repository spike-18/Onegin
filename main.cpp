#include "lib.cpp"


#ifndef DEBUG
    #define RELEASE
#endif


int main(int argc, const char *argv[])
{

    int test_arr[] = {1,2,3,4,11,12,13,14,21,22,23,24,31,32,33,34};
    size_t sizeX = 4;
    size_t sizeY = 4;

    print_arr_1(test_arr, sizeX, sizeY);

    return 0;
}