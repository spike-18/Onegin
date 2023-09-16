#include "lib.hpp"


void Sort(int* data, int left, int right)
{
    if(left < right)
    switch (right - left)
    {
    case ONE_ELEM:
        return;
        break;

    case TWO_ELEM:
        sort_two(data, left, right);
        break;
    
    case THREE_ELEM:
        sort_three(data, left, right);
        break;
    
    default:
        int mid = partition(data, left, right);
        Sort(data, left, mid);
        Sort(data, mid+1, right);

        break;
    }
}

int partition(int* data, int left, int right)
{

    #ifdef DEBUG
        int lb = left;
        int rb = right;
        printf("Partition %d - %d:\n", left, right);
    #endif

    int piv = (right + left) / 2;
    int mid = data[piv];

    while (1)
    {
        #ifdef DEBUG
            print_data(data, lb, rb ,left, right, piv);
        #endif

        while(data[left] < mid)
            left++;
        while(data[right] > mid)
            right++;
        
        if(left >= right)
            return right;
        swap(data, left, right);

    }

}


void sort_two(int* data, int left, int right)
{
    if(data[left] > data[right])
        swap(data, left, right);
}


void sort_three(int* data, int left, int right)
{
    if(data[left] > data[left+1])
        swap(data, left, left+1);
    if(data[left+1] > data[right])
        swap(data,left+1, right);
}


void swap(int* data, int left, int right)
{
    int c = data[left];
    data[left] = data[right];
    data[right] = c;
}


void print_data(int* data, int lb, int rb, int left, int right, int piv)
{
    
    for(int i = lb; i <= rb; i++)
        printf("%02d ", i);
    printf("\n");

    for (int i = lb; i <= rb; i++)
    {
        if(i == piv){
            printf(GRN "%02d " STD, data[i]);
            continue;
        }
        else if( i < left)
            printf(CYN);
        else if(i == left)
            printf(BLU);
        else if(i == right)
            printf(RED);
        else if(left < i && i < piv && piv < right)
            printf(BLU);
        else if(left < i && i < piv && piv >= right)
            printf(STD);
        else if(i < right)
            printf(RED);
        else if( i > right)
            printf(MAG);
        printf("%02d " STD, data[i]);
    }    
    
    printf("\n");
    for (int i = lb; i <= rb; i++)
    {
        if ( i == piv )
            printf("/\\");
        else
            printf("___");
    }

    printf("\n\n");
}