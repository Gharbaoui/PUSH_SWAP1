#include "checker.h"

int	filled_array(int *arr, int size, char **nums)
{
	int		i;
	long	val;

	i = 0;
	while (++i <= size)
	{
		if (!ft_isnumber(nums[i]))
			return (0);
		val = ft_atoi(nums[i]);
		if (outside_range(val))
			return (0);
		if (ft_passed(arr, val, i - 1))
			return (0);
		arr[i - 1] = val;
	}
	return (1);
}

int	outside_range(long val)
{
	if (val > INT_MAX)
		return (1);
	if (val < INT_MIN)
		return (1);
	return (0);
}

int	ft_passed(int *arr, int val, int index)
{
	while (--index >= 0)
		if (arr[index] == val)
			return (1);
	return (0);
}
