#include "push_swap.h"


void display_stack(t_stack *a, int just_value)
{
    t_stack *help;
    
    help = a;
    while (help)
    {
        printf("|%d|\n", help->data->value);
        if (just_value == 0)
        {
            printf("dir: %d\n", help->data->direction);
            printf("step: %d\n", help->data->steps);
        }
        help = help->next;
    }
}

void display_full(t_all *all, int also_stacks, int stack_with_inf, int finf)
{
    if (finf){
        printf ("min {%d} med {%d} max {%d}\n", all->min, all->medien, all->max);
        printf("-------------------------------------\n");
        printf ("members of a {%d}\n", all->mem_of_a);
    }
    if (also_stacks)
    {
        if (stack_with_inf)
            display_stack(all->a, 0);
        else
            display_stack(all->a, 1);
    }
    if (finf){
        printf("=====================================\n");
        printf ("members of b {%d}\n", all->mem_of_b);
    }
    if (also_stacks)
    {
        if (stack_with_inf)
            display_stack(all->b, 0);
        else
            display_stack(all->b, 1);
    }
}
