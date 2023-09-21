#include "lib.hpp"


inline void inc(void** ptr, size_t el_size) { *ptr = (void*) ( (char*) *ptr + el_size ); }
inline void dec(void** ptr, size_t el_size) { *ptr = (void*) ( (char*) *ptr - el_size ); }

void Sort(void* data, size_t len, size_t el_size, int (*comp) (const void* a, const void* b))
{
    switch (len)
    {
        case ONE_ELEM:
            return;
            break;

        //case TWO_ELEM:
        //    sort_two(data, left, right, comp);
        //    break;

        //case THREE_ELEM:
        //    sort_three(data, left, right, comp);
        //    break;

        default:
        //printf("%d -len", len);
            void* mid = partition(data, (char*) data + (len-1)*el_size, el_size, comp);
            Sort(data, ((char*)mid - (char*)data) / el_size + 1, el_size, comp);
            Sort((char*)mid + el_size, len - (((char*)mid - (char*)data) / el_size) - 1, el_size, comp);
            break;
    }
}


void* partition(void* left, void* right, size_t el_size, int (*comp) (const void* a, const void* b))
{
    //printf("Partition\n");
    size_t len = ( (char*) right - (char*) left ) / el_size + 1;

    void* piv = (void*) ((char*)left + (len/2-1)*el_size);
    //printf("%d %d %d %d\n", len, *(int*)left, *(int*)piv, *(int*)right);

    #ifdef DEBUG
        int* lb = (int*) left;
        int* rb = (int*) right;
    #endif


    while (1)
    {
        #ifdef DEBUG
            //print_data(lb, rb, (int*) left, (int*) right, (int*) piv);
        #endif

        while(comp(left, piv) < 0)
            inc(&left, el_size);
        while(comp(right, piv) > 0)
            dec(&right, el_size);

        if(left >= right)
            return right;

         #ifdef DEBUG
            if (left == piv)
                piv = right;
            else
            if (right == piv)
                piv = left;
        #endif

        swap(left, right, el_size);

        #ifdef DEBUG
            //print_data(lb, rb, (int*) left, (int*) right, (int*) piv);
        #endif

        inc(&left, el_size);
        dec(&right, el_size);
    }

}


void swap(void* a, void* b, size_t el_size)
{
    if(el_size){}
    int c  =  *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = c;
    //printf("Swap %d to %d\n", *(int*)a, *(int*)b);

}


/*

void sort_two(void* data, void* left, void* right, int (*comp) (const void* a, const void* b))
{
    if(comp(&data[left], &data[right]) > 0)
        swap(data, left, right);
}


void sort_three(void* data, void* left, void* right, int (*comp) (const void* a, const void* b))
{
    if(comp(&data[left], &data[right]) > 0)
        swap(data, left, right);
    if(comp(&data[left], &data[left+1]) > 0)
        swap(data, left, left+1);
    if(comp(&data[left+1], &data[right]) > 0)
        swap(data, left+1, right);
}
*/





int str_frw_comp (void* a, void* b)
{
    return strcmp(*(const char* *) a, *(const char* *) b);
}

int int_comp (void* a, void* b)
{
    return *(int *) a - *(int *) b;
}


#ifdef DEBUG

void print_data(int* lb, int* rb, int* left, int* right, int* piv)
{

    for(int* i = lb; i <= rb; i++)
        printf("%02d ", i-lb);
    printf("\n");

    for (int* i = lb; i <= rb; i++)
    {
        if (i == piv)
            printf(GRN);
        else if (i < left)
            printf(CYN);
        else if (i == left)
            printf(BLU);
        else if (i == right)
            printf(RED);
        else if (left < i && i < piv && piv < right)
            printf(BLU);
        else if (left < piv && piv < i && i < right)
            printf(RED);
        else if (i > right)
            printf(MAG);
        else
            printf(STD);

        printf("%02d " STD, *i);
    }

    printf("\n");
    for (int* i = lb; i <= rb; i++)
    {
        if (i == piv)
            printf("/\\ ");
        else if (i == left)
            printf("LL ");
        else if (i == right)
            printf("RR ");
        else
            printf("%c %c", ' ', ' ');
    }

    printf("\n\n\n");
}

#endif
void test_sort(int* data, int data_size)
{
    for (int i = 0; i < data_size-1; i++)
        if(data[i+1] < data[i])
        {
            printf(RED "\nARRAY BADLY SORTED\n" STD);
            return;
        }

    printf(GRN "\nSORT TEST PASSED\n" STD);
}


