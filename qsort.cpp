#include "lib.hpp"


void Sort(int* data, int left, int right)
{
    switch (right - left)
    {
    case ONE_ELEM:
        return;
        break;

    case TWO_ELEM:
        sort_two(data, left, right);
        break;
    /*
    case THREE_ELEM:
        sort_three(data, left, right);
        break;
    */
    default:
        int mid = partition(data, left, right);
        Sort(data, left, mid);
        Sort(data, mid+1, right);
        break;
    }
}

int partition(int* data, int left, int right)
{
    int pivot = (int) (right + left) / 2;
    int mid = data[pivot];
    while(left < right)
    {
        while (data[left] < mid)
            left++;
        while (data[right] > mid)
            right--;
        swap(data, left, right);
    }

    print_data(data, left, right);

    return left;
}

void sort_two(int* data, int left, int right)
{
    if(data[left] > data[right])
        swap(data, left, right);
}

void sort_three(int* data, int left, int right)
{
    if(data||left||right){}
}

void swap(int* data, int left, int right)
{
    int c = data[left];
    data[left] = data[right];
    data[right] = c;
}

void print_data(int* data, int left, int right)
{
    for(int i = 0; i < 14; i++)
        printf("%02d ", i);
    printf("\n");

    printf(CYN);
    for(int i = 0; i < left; i++)
        printf("%02d ", data[i]);
    
    printf(BLU);
    for(int i = left; i < (right+left)/2; i++)
        printf("%02d ", data[i]);
    
    printf(GRN);
    printf("%02d ", data[(right+left)/2]);
    
    printf(RED);
    for(int i = (right+left)/2 + 1; i <= right; i++)
        printf("%02d ", data[i]);
    
    printf(MAG);
    for(int i = right + 1; i < 14; i++)
        printf("%02d ", data[i]);
    
    printf(STD);
    printf("\n\n");
}