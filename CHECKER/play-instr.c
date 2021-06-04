#include "checker.h"
#include "../get_next_line/get_next_line.h"

void play_mode(t_all *all)
{
    int ret;
    int count;
    char *line;

    count = 0;
    while (1)
    {
        ret = get_next_line(&line);
        if (ret == 0){
            if (*line)
            {
                write(2, "Error\n", 6);
                exit(1);
            }
            break ;
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
        else
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        count++;
    }
}









