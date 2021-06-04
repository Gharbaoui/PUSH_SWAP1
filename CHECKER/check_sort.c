#include "checker.h"

int	*from_linked(t_stack *s, int size)
{
	int	*arr;
	int	i;

	i = -1;
	arr = malloc(sizeof(int) * size);
	while (s)
	{
		arr[++i] = s->data->value;
		s = s->next;
	}
	return (arr);
}

int	check_if_sorted(t_all *bs)
{
	int	*arr;

	if (bs->mem_of_b)
		return (0);
	arr = from_linked(bs->a, bs->mem_of_a);
	if (ft_is_sorted(arr, bs->mem_of_a))
		return (1);
	return (0);
}
