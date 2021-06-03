#include "push_swap.h"

void play_mode(t_all *all)
{
    int i;
    char *line;

    line = malloc(10);
    while (1)
    {
        read(0, line, 9);
        i = -1;
        while (line[++i])
        {
            if (line[i] == '\n')
            {
                line[i] = 0;
                break ;
            }
        }
        if (*line)
        {
            printf ("SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS\n");
            display_full(all, 1, 0, 1);
            printf("\n\n\n");
        }
        if (!ft_strcmp(line, "sa"))
            gen_swap(all, "sa");
        else if (!ft_strcmp(line, "sb"))
            gen_swap(all, "sb");
        else if (!ft_strcmp(line, "ss"))
            gen_swap(all, "ss");
        else if (!ft_strcmp(line, "pa"))
            ft_push(all, "pa");
        else if (!ft_strcmp(line, "pb"))
            ft_push(all, "pb");
        else if (!ft_strcmp(line, "ra"))
            rotat_up(all, "ra");
        else if (!ft_strcmp(line, "rb"))
            rotat_up(all, "rb");
        else if (!ft_strcmp(line, "rr"))
            rotat_up(all, "rr");
        else if (!ft_strcmp(line, "rra"))
            rotat_down(all, "rra");
        else if (!ft_strcmp(line, "rrb"))
            rotat_down(all, "rrb");
        else if (!ft_strcmp(line, "rrr"))
            rotat_down(all, "rrr");
        if (*line){
            printf("+++++++++++++++++++++++++\n");
            display_full(all, 1, 0, 1);
        }
    }
    
}









