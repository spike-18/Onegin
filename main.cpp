#include "lib.cpp"


#ifndef DEBUG
    #define RELEASE
#endif


int main(int argc, const char *argv[])
{

    size_t sizeX = 4;
    size_t sizeY = 4;

    int test_sep[] = {1,2,3,4,11,12,13,14,21,22,23,24,31,32,33,34};
    int test_utd[] = {(int) sizeX, (int) sizeY,                             // size
                      1,2,3,4,11,12,13,14,21,22,23,24,31,32,33,34};         // array

    print_separately(test_sep, sizeX, sizeY);
    print_united(test_utd);



    return 0;
} 