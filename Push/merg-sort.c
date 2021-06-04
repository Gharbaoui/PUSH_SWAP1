#include "push_swap.h"

void merg_sort(int *arr, int l, int r)
{
    int med;
    
    if (r > l)
    {
        med = l + ((r - l) / 2);
        merg_sort(arr, l, med);
        merg_sort(arr, med + 1, r);
        merg_arrs(arr, l, r, med);
    }
}

void merg_arrs(int *arr, int l, int r, int med)
{
    int *left;
    int *right;
    
    left = make_array(arr, l, med);
    right = make_array(arr, med + 1, r);
    merg_two_sorted(arr, left, right, conctnate_two_nums(l, r));
    free(left);
    free(right);
}


void merg_two_sorted(int *arr, int *left, int *right, long l_r)
{
    int l;
    int r;
    int i;
    int j;
    int k;
    
    recover_nums(l_r, &l, &r); /// i will grourp this variables
    k = l;//
    i = 0;//
    j = 0;///
    l_r = l + ((r - l) / 2);///
    while (i < (l_r - l + 1) && j < r - l_r)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++; 
    }
    if (j < r - l_r)
        fill_rest(arr, right + j, k, (r - l_r) - j);
    else if (i < (l_r - l + 1))
        fill_rest(arr, left + i, k, (l_r - l + 1) - i);
}

void fill_rest(int *arr, int *toadd, int index, int size)
{
    int i;
    
    i = -1;
    while (++i < size){
        arr[index] = toadd[i];
        index++;
    }
}




int *make_array(int *arr, int start, int end)
{
    int *newarr;
    int i;
    int j;
    
    i = start - 1;
    j = -1;
    newarr = malloc(sizeof(int) * (end - start + 1));
    while (++i <= end)
        newarr[++j] = arr[i];
    return newarr;
}

long conctnate_two_nums(int a, int b)
{
    long both;
    
    both = a;
    both = both << (sizeof(int) * 8);
    both = both | b;
    return both;
}

void recover_nums(long both, int *a, int *b)
{
    *a = both >> (sizeof(int) * 8);
    both = both << (sizeof(int) * 8);
    *b = both >> (sizeof(int) * 8);
}

