#include "lib.hpp"


inline void inc (void** ptr, size_t el_size) { *ptr = (void*) ( (char*) *ptr + el_size ); }
inline void dec (void** ptr, size_t el_size) { *ptr = (void*) ( (char*) *ptr - el_size ); }


void Sort (void* data, size_t len, size_t el_size, int (*comp) (const void* a, const void* b))
{
    switch (len)
    {
        case ONE_ELEM:
            return;
            break;

        case TWO_ELEM:
            sort_two((char*) data, (char*) data + el_size*(len-1), el_size, comp);
            break;

        case THREE_ELEM:
            sort_three((char*) data, (char*) data + el_size*(len-1), el_size, comp);
            break;

        default:
            void* mid = partition(data, (char*) data + el_size*(len-1), el_size, comp);
            Sort( data,
                  ((char*) mid - (char*) data) / el_size + 1,
                  el_size,
                  comp );
            Sort( (char*) mid + el_size,
                  len - (((char*) mid - (char*) data) / el_size) - 1,
                  el_size,
                  comp );
            break;
    }
}


void* partition (void* left, void* right, size_t el_size, int (*comp) (const void* a, const void* b))
{
    size_t      len = ((char*)right - (char*)left) / el_size + 1;
    void*       piv = (void*) ((char*)left + (len-1)/2*el_size);
    const void* mid = (const void*) (*(char* *)piv);

    #ifdef DEBUG
        void* lb = left;
        void* rb = right;
    #endif

    while (1)
    {

        #ifdef DEBUG
            print_data((int**) lb, (int**) rb, (int**) left, (int**) right, (int**) piv);
        #endif

        while((*comp)((void *) left, (void *) &mid) < 0)
            inc(&left, el_size);
        while((*comp)((void *) right, (void *) &mid) > 0)
            dec(&right, el_size);

        if ((char*) left >= (char*) right)
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
            print_data((int**) lb, (int**) rb, (int**) left, (int**) right, (int**) piv);
        #endif

        inc(&left, el_size);
        dec(&right, el_size);
    }
}


void swap (void* a, void* b, size_t el_size)
{
    char *_a = (char*) a, *_b = (char*) b;
    size_t bytes = el_size;
    while (bytes > 0)
    {
        char _tmp = *_a;
        *_a++ = *_b;
        *_b++ = _tmp;
        bytes--;
    }
}


void sort_two(char* left, char* right, size_t el_size, int (*comp) (const void* a, const void* b))
{
    if ((*comp)(left, right) > 0)
        swap(left, right, el_size);
}


void sort_three(char* left, char* right, size_t el_size, int (*comp) (const void* a, const void* b))
{
    if ((*comp)(left, right) > 0)
        swap(left, right, el_size);
    if ((*comp)(left, left + el_size) > 0)
        swap(left, left + el_size, el_size);
    if ((*comp)(left + el_size, left + 2*el_size) > 0)
        swap(left + el_size, left + 2*el_size, el_size);
}


int str_frw_comp (void* a, void* b)
{
    return strcmp(*(const char* *) a, *(const char* *) b);
}


int str_bkw_comp (void* a, void* b)
{
    const char* _a = *(const char* *) a;
    const char* _b = *(const char* *) b;

    size_t a_len = 0;
    size_t b_len = 0;

    while(_a[a_len] != '\0')
        a_len++;
    while(_b[b_len] != '\0')
        b_len++;

    while(a_len && b_len)
    {
        if (isignored(_a[a_len]))
        {
            a_len--;
            continue;
        }
        if (isignored(_b[b_len]))
        {
            b_len--;
            continue;
        }
        if (_a[a_len] != _b[b_len])
            return _a[a_len] > _b[b_len] ? 1 : -1;
        a_len--;
        b_len--;
    }

    return 0;
}


#ifdef DEBUG

    int int_comp (void* a, void* b)
    {
        return **(int**) a - **(int**) b;
    }


    void print_data (int** lb, int** rb, int** left, int** right, int** piv)
    {

        for(int** i = lb; i <= rb; i++)
            printf("%02d ", i-lb);
        printf("\n");

        for (int** i = lb; i <= rb; i++)
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

            printf("%02d " STD, **i);
        }

        printf("\n");
        for (int** i = lb; i <= rb; i++)
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

    void test_sort (int** data, int data_size)
    {
        for (int i = 0; i < data_size-1; i++)
            if (*data[i+1] < *data[i])
            {
                printf(RED "\nARRAY BADLY SORTED\n" STD);
                return;
            }

        printf(GRN "\nSORT TEST PASSED\n" STD);
    }

#endif
