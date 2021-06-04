#include "checker.h"


////// swap
void gen_swap(t_all *all, char *sname)
{
    if (!ft_strcmp(sname, "sa"))
    {
        if (all->mem_of_a > 1){
            //print_str(sname);
            swap_stack(all->a, all->mem_of_a);
        }
    }
    else if (!ft_strcmp(sname, "sb"))
    {
        if (all->mem_of_b > 1){
            //print_str(sname);
            swap_stack(all->b, all->mem_of_b);
        }
    }else if (!ft_strcmp(sname, "ss"))
    {
        if (all->mem_of_b > 1 || all->mem_of_a > 1)
        {
            swap_stack(all->a, all->mem_of_a);
            swap_stack(all->b, all->mem_of_b);
            //print_str(sname);
        }
    }
}

void swap_stack(t_stack *a, int size)
{
    int help;

    if (size > 1)
    {
        help = a->data->value;
        a->data->value = a->next->data->value;
        a->next->data->value = help;
    }
}


///////// push_value
void ft_push(t_all *all, char *pname)
{
    if (!(ft_strcmp(pname, "pa")))
    {
        //// source is b dst is a
        if (all->mem_of_b){
            push_exact(&all->a, &all->b, all->mem_of_b);
            all->mem_of_b--;
            all->mem_of_a++;
            //print_str(pname);
        }
    }
    else if (!ft_strcmp(pname, "pb"))
    {
        if (all->mem_of_a){
            push_exact(&all->b, &all->a, all->mem_of_a);
            all->mem_of_a--;
            all->mem_of_b++;
            //print_str(pname);
        }
    }
}

void push_exact(t_stack **dst, t_stack **src, int srcsize)
{
    t_stack *help;

    if (srcsize)
    {
        help = *src;
        *src = (*src)->next;
        help->next = *dst;
        *dst = help;
    }
}

/////////// rotation

void rotat_up(t_all *all, char *rname)
{
    if (!ft_strcmp(rname, "ra"))
    {
        if (all->mem_of_a > 1)
        {
            rot_exact_up(&all->a, all->mem_of_a);
            //print_str(rname);
        }
    }else if (!ft_strcmp(rname, "rb"))
    {
        if (all->mem_of_b){
            rot_exact_up(&all->b, all->mem_of_b);
            //print_str(rname);
        }
    }else if (!ft_strcmp(rname, "rr"))
    {
        if (all->mem_of_a > 1|| all->mem_of_b > 1){
           // print_str(rname);
            rot_exact_up(&all->a, all->mem_of_a);
            rot_exact_up(&all->b, all->mem_of_b);
        }
    }
}

void rot_exact_up(t_stack **a, int size)
{
    t_stack *first;
    t_stack *help;

    if (size > 1)
    {
        first = *a;
        *a = (*a)->next;
        help = *a;
        while (help->next)
            help = help->next;
        help->next = first;
        help->next->next = NULL;
    }
}

////////// rotate down 

void rotat_down(t_all *all, char *rrname)
{
    if (!ft_strcmp(rrname, "rra"))
    {
        rot_exact_down(&all->a, all->mem_of_a);
        //print_str(rrname);
    }
    else if (!ft_strcmp(rrname, "rrb"))
    {
        rot_exact_down(&all->b, all->mem_of_b);
        //print_str(rrname);
    }
    else if (!ft_strcmp(rrname, "rrr"))
    {
        rot_exact_down(&all->a, all->mem_of_a);
        rot_exact_down(&all->b, all->mem_of_b);
        //print_str(rrname);
    }
}


void rot_exact_down(t_stack **s, int size)
{
    t_stack *last;
    t_stack *bef_last;
    t_stack *second;

    if (size > 1)
    {
        if (size == 2)
        {
            last = (*s)->next;
            last->next = *s;
            *s = last;
            (*s)->next->next = NULL;
            return ;
        }
        second = *s;
        while (second->next->next)
            second = second->next;
        bef_last = second;
        second = second->next;
        second->next = *s;
        bef_last->next = NULL;
        *s = second;
    }
}


