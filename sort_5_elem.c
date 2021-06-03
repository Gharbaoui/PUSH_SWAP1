#include "push_swap.h"

void sort_f_elem(t_all *bs)
{
    mov_help(bs, bs->min);
    mov_help(bs, bs->sec_min);
    sort_th_elem(bs);
    ft_push(bs, "pa");
    ft_push(bs, "pa");
}

void mov_help(t_all *bs, int value)
{
    t_stack *help;
    t_excu_stps stp;
    
    movment_to_top_calc(bs);
    help = get_ref_by_value(bs->a, value);
    stp.ex_stps_a = help->data->steps;
    stp.dir_a = help->data->direction;
    stp.ex_stps_b = 0;
    stp.dir_b = 1;
    stp.pb = 1;
    stp.pa = 0;
    run_exuc_struct(bs, stp);
    
}

void run_exuc_struct(t_all *bs, t_excu_stps stp)
{
    int i;

    i = -1;
    while (++i < stp.ex_stps_a)
    {
        if (stp.dir_a == 1)
            rotat_up(bs, "ra");
        else
            rotat_down(bs, "rra");
    }
    i = -1;
    while (++i < stp.ex_stps_b)
    {
       if (stp.dir_b == 1)
            rotat_up(bs, "rb");
        else
            rotat_down(bs, "rrb");
    }
    i = -1;
    while (++i < stp.pa)
        ft_push(bs, "pa");
    i = -1;
    while (++i < stp.pb)
        ft_push(bs, "pb");
}

void movment_to_top_calc(t_all *bs)
{
    calc_mov_for_one(bs->a, bs->mem_of_a);
    calc_mov_for_one(bs->b, bs->mem_of_b);
}

void calc_mov_for_one(t_stack *s, int size)
{
    int mid_index;
    int i;

    if (!size)
        return ;
    i = -1;
    mid_index = size / 2;
    while (++i <= mid_index)
    {
        s->data->direction = 1;
        s->data->steps = i;
        s = s->next;
    }
    --i;
    while (++i < size)
    {
        s->data->direction = -1;
        s->data->steps = (size - 1) - i + 1;
        s = s->next;
    }
}

t_stack *get_ref_by_value(t_stack *s, int value)
{
    while (s)
    {
        if (s->data->value == value)
            return s;
        s = s->next;
    }
    return NULL;
}
