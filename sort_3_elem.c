#include "push_swap.h"

void sort_th_elem(t_all *bs)
{
    int top;
    int bot;
    int med;

    top = bs->a->data->value;
    med = bs->a->next->data->value;
    bot = bs->a->next->next->data->value;
    if (top > med)
    {
        if (med < bot)
        {
            if (bot > top)
                gen_swap(bs, "sa");
            else
                rotat_up(bs, "ra");
        }
        else
        {
            gen_swap(bs, "sa");
            rotat_down(bs, "rra");
        }
    }
    else
    {
        if (top > bot)
            rotat_down(bs, "rra");
        else if (med > bot){
            gen_swap(bs, "sa");
            rotat_up(bs, "ra");
        }
    }
}


