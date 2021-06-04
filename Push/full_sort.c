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
        run_exuc_struct(bs, stp);
    }
    //// here i need to move
    mov_min_to_top(bs);
}

void mov_min_to_top(t_all *bs)
{
    t_num_info *min;
    t_excu_stps stp;

    calc_mov_for_one(bs->a, bs->mem_of_a);
    min = get_ref_by_value(bs->a, bs->min)->data;
    stp.pa = 0;
    stp.pb = 0;
    stp.ex_stps_b = 0;
    stp.ex_stps_a = min->steps;
    stp.dir_a = min->direction;
    run_exuc_struct(bs, stp);
}

void fill_stps_in_small_stps(t_all *bs, t_excu_stps *stp)
{
    t_stack *a;
    t_stack *b;
    int movments;
    int last_movs;

    a = bs->a;
    b = bs->b;
    movments = -1;
    movment_to_top_calc(bs);
    while (b)
    {
        movments = movment_required(a, b->data, stp, movments);
        b = b->next;
    }
}

int movment_required(t_stack *a, t_num_info *b_inf, t_excu_stps *stp, int last_movs)
{
    int tot;
    t_num_info *a_inf;

    a_inf = right_a_for_bvalue(a, b_inf->value);
    tot = a_inf->steps + b_inf->steps;
    if (tot < last_movs || last_movs == -1)
    {
        stp->dir_a = a_inf->direction;
        stp->dir_b = b_inf->direction;
        stp->ex_stps_a = a_inf->steps;
        stp->ex_stps_b = b_inf->steps;
        stp->pa = 1;
        return tot;
    }
    return last_movs;
}

t_num_info *right_a_for_bvalue(t_stack *a, int value)
{
    int last_big;
    t_num_info *ref;

    while (a)
    {
        if (value < a->data->value)
        {
            last_big = a->data->value;
            ref = a->data;
            break ;
        }
        a = a->next;
    }
    while (a)
    {
        if (value < a->data->value)
        {
            if (a->data->value < last_big)
            {
                last_big = a->data->value;
                ref = a->data;
            }
        }
        a = a->next;
    }
    return ref;
}

