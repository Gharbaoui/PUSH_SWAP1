#include "push_swap.h"

void free_all(t_all *bs)
{
    free_stack(bs->a);
    free_stack(bs->b);
}

void free_stack(t_stack *s)
{
    t_stack *next;
   
    if (!s)
        return ;
    if (s->next)
    {
        next = s->next;
    }
    while (next)
    {
        free_node(s);
        s = next;
        next = s->next;
    }
}

void free_node(t_stack *obj)
{
    free(obj->data);
    free(obj);
}
