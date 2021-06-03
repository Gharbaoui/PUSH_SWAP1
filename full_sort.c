#include "push_swap.h"

void full_sort(t_all *bs)
{
    start_prep_in_stack_b(bs);
    start_sorting_mov(bs);
}

void start_prep_in_stack_b(t_all *bs)
{

    int a;
    int cub;
    int prb;
    while (bs->mem_of_a > 2)
    {
        a = bs->a->data->value;
        if (!check_if_value_there(bs->a->data->value, 2, bs->min, bs->max))
        {
            ft_push(bs, "pb");
            cub = a;
            if (bs->b->data->value > bs->medien && bs->mem_of_b > 1)
            {
                prb = bs->b->next->data->value;
                if (bs->b->next->data->value <= bs->medien)
                    rotat_up(bs, "rb");
            }
        }
        else
        {
            rotat_up(bs, "ra");
        }
    }
    if (bs->a->data->value < bs->a->next->data->value)
        gen_swap(bs, "sa");
    ft_push(bs, "pa"); //// this will be always true becaus the max is at top so any number 
    // above will in valid order
}

int check_if_value_there(int value, int size,  ...)
{
    va_list list;
    int i;
    int val;
    int ret;

    ret = 0;
    i = -1;
    va_start(list, size);
    while (++i < size)
    {
        val = va_arg(list, int);
        if (val == value)
        {
            ret = 1;
            break ;
        }
    }
    va_end(list);
    return ret;
}

void init_exec_stp(t_excu_stps *stp)
{
    stp->ex_stps_b = -1;
    stp->ex_stps_a = -1;
    stp->dir_a = 0;
    stp->dir_b = 0;
    stp->pb = 0;
    stp->pa = 0;
}


void start_sorting_mov(t_all *bs)
{
    t_excu_stps stp;

    while (bs->mem_of_b)
    {
        init_exec_stp(&stp);
        fill_stps_in_small_stps(bs, &stp);
    }
}

void fill_stps_in_small_stps(t_all *bs, t_excu_stps *stp)
{
    t_stack *a;
    t_stack *b;
    int movments;
    int last_movs;
    
    last_movs = -1;
    a = bs->a;
    b = bs->b;
    movment_to_top_calc(bs);
    while (b)
    {
        movments = movment_required(a, b);     ///// this will return numbers of actions to move b object to his place in a
        if (last_movs == -1 || movments < last_movs)
            last_movs = movments;
        b = b->next;
    }
}

int movment_required(t_stack *a, t_stack *b)
{
    t_num_info *inf;
    
}








