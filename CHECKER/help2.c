#include "checker.h"

void	rot_exact_up(t_stack **a, int size)
{
	t_stack	*first;
	t_stack	*help;

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

void	rotat_down(t_all *all, char *rrname)
{
	if (!ft_strcmp(rrname, "rra"))
	{
		rot_exact_down(&all->a, all->mem_of_a);
	}
	else if (!ft_strcmp(rrname, "rrb"))
	{
		rot_exact_down(&all->b, all->mem_of_b);
	}
	else if (!ft_strcmp(rrname, "rrr"))
	{
		rot_exact_down(&all->a, all->mem_of_a);
		rot_exact_down(&all->b, all->mem_of_b);
	}
}

void	rot_exact_down(t_stack **s, int size)
{
	t_stack	*last;
	t_stack	*bef_last;
	t_stack	*second;

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
