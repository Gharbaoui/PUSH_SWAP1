#include "checker.h"

void	gen_swap(t_all *all, char *sname)
{
	if (!ft_strcmp(sname, "sa"))
	{
		if (all->mem_of_a > 1)
			swap_stack(all->a, all->mem_of_a);
	}
	else if (!ft_strcmp(sname, "sb"))
	{
		if (all->mem_of_b > 1)
			swap_stack(all->b, all->mem_of_b);
	}
	else if (!ft_strcmp(sname, "ss"))
	{
		if (all->mem_of_b > 1 || all->mem_of_a > 1)
		{
			swap_stack(all->a, all->mem_of_a);
			swap_stack(all->b, all->mem_of_b);
		}
	}
}

void	swap_stack(t_stack *a, int size)
{
	int	help;

	if (size > 1)
	{
		help = a->data->value;
		a->data->value = a->next->data->value;
		a->next->data->value = help;
	}
}

void	ft_push(t_all *all, char *pname)
{
	if (!(ft_strcmp(pname, "pa")))
	{
		if (all->mem_of_b)
		{
			push_exact(&all->a, &all->b, all->mem_of_b);
			all->mem_of_b--;
			all->mem_of_a++;
		}
	}
	else if (!ft_strcmp(pname, "pb"))
	{
		if (all->mem_of_a)
		{
			push_exact(&all->b, &all->a, all->mem_of_a);
			all->mem_of_a--;
			all->mem_of_b++;
		}
	}
}

void	push_exact(t_stack **dst, t_stack **src, int srcsize)
{
	t_stack	*help;

	if (srcsize)
	{
		help = *src;
		*src = (*src)->next;
		help->next = *dst;
		*dst = help;
	}
}

void	rotat_up(t_all *all, char *rname)
{
	if (!ft_strcmp(rname, "ra"))
	{
		if (all->mem_of_a > 1)
			rot_exact_up(&all->a, all->mem_of_a);
	}
	else if (!ft_strcmp(rname, "rb"))
	{
		if (all->mem_of_b)
			rot_exact_up(&all->b, all->mem_of_b);
	}
	else if (!ft_strcmp(rname, "rr"))
	{
		if (all->mem_of_a > 1 || all->mem_of_b > 1)
		{
			rot_exact_up(&all->a, all->mem_of_a);
			rot_exact_up(&all->b, all->mem_of_b);
		}
	}
}
