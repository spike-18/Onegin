#include "lib.hpp"


void Sort(char** data, int left, int right, int (*comp)(void* a, void* b))
{
    //printf("Sort\n");
    if(left < right)
        switch (right - left)
        {
            case ONE_ELEM:
                return;
                break;

            case TWO_ELEM:
                sort_two(data, left, right, comp);
                break;

            case THREE_ELEM:
                sort_three(data, left, right, comp);
                break;

            default:
                int mid = partition(data, left, right, comp);
                Sort(data, left, mid, comp);
                Sort(data, mid+1, right, comp);
                break;
        }
}

int partition(char** data, int left, int right, int (*comp)(void* a, void* b))
{
    //printf("Partition\n");
    int piv = (right + left) / 2;

    while (1)
    {
        //printf("%s\n", data[right]);
        while(comp(&data[left], &(data[piv])) < 0)
            left++;
        while(comp(&data[right], &data[piv]) > 0)
            right--;

        if(left >= right)
            return right;

        swap(data, left++, right--);

    }

}


void sort_two(char** data, int left, int right, int (*comp)(void* a, void* b))
{
    if(comp(&data[left], &data[right]) > 0)
        swap(data, left, right);
}


void sort_three(char** data, int left, int right, int (*comp)(void* a, void* b))
{
    if(comp(&data[left], &data[right]) > 0)
        swap(data, left, right);
    if(comp(&data[left], &data[left+1]) > 0)
        swap(data, left, left+1);
    if(comp(&data[left+1], &data[right]) > 0)
        swap(data, left+1, right);
}



void swap(char** data, int left, int right)
{
    char* c  =  data[left];
    data[left]  = data[right];
    data[right] = c;
}


int comparator(void* a, void* b)
{
    return strcmp(*(const char* *)a, *(const char* *)b);
}


