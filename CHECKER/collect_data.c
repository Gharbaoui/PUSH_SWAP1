#include "checker.h"

int	collect_numbers(int size, char **nums, t_all **bs)
{
	int	*arr;

	arr = malloc(sizeof(int) * (size - 1));
	if (!filled_array(arr, size - 1, nums))
	{
		free(arr);
		write(2, "Error\n", 6);
		exit(1);
	}
	fill_valid_info(bs, arr, size - 1);
	free(arr);
	return (1);
}

void	fill_valid_info(t_all **bs, int *arr, int size)
{
	*bs = malloc(sizeof(t_all));
	(*bs)->b = NULL;
	(*bs)->mem_of_b = 0;
	(*bs)->size = size;
	(*bs)->a = from_array_to_stack(arr, size);
	(*bs)->mem_of_a = size;
}

int	ft_is_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (++i < size)
		if (arr[i - 1] > arr[i])
			return (0);
	return (1);
}

t_stack	*from_array_to_stack(int *arr, int size)
{
	t_stack	*st;
	t_stack	*help;
	t_stack	*head;
	int		i;

	i = 0;
	st = malloc(sizeof(t_stack));
	st->next = NULL;
	st->data = get_one_value_inf(arr[i], 0, 0);
	head = st;
	while (++i < size)
	{
		help = malloc(sizeof(t_stack));
		help->next = NULL;
		help->data = get_one_value_inf(arr[i], 0, 0);
		st->next = help;
		st = help;
	}
	return (head);
}

t_num_info	*get_one_value_inf(int value, short dir, short stp)
{
	t_num_info	*tmp;

	tmp = malloc(sizeof(t_num_info));
	tmp->value = value;
	tmp->direction = dir;
	tmp->steps = stp;
	return (tmp);
}
