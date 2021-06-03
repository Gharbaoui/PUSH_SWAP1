#include "push_swap.h"

void start_sort(t_all *bs)
{
    if (bs->size <= 3)
        sort_th_elem(bs);
    else if (bs->size == 5)
        sort_f_elem(bs);
    else 
        full_sort(bs);
}
