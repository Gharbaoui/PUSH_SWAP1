#include "checker.h"

int	help_ft_atoi(const char *str, int np)
{
	long	result;
	long	max;

	result = 0;
	max = 9223372036854775807;
	while (ft_isdigit(*str))
	{
		if (result <= (max - (*str - '0')) / 10)
			result = (result * 10) + *str - '0';
		else
		{
			if (np == -1)
				result = 0;
			else
				result = -1;
			break ;
		}
		str++;
	}
	return (result * np);
}

long	ft_atoi(const char *str)
{
	long	result;
	int		np;
	long	max;

	result = 0;
	max = 9223372036854775807;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			np = -1;
		else
			np = 1;
	}
	return (help_ft_atoi(str, np));
}
