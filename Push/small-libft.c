#include "push_swap.h"

long    ft_atoi(const char *str)
{
	long	result;
	int		np;
	long	max;

	np = 1;
	result = 0;
	max = 9223372036854775807;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		np = (*str++ == '-') ? -1 : 1;
	while (ft_isdigit(*str))
	{
		if (result <= (max - (*str - '0')) / 10)
			result = (result * 10) + *str - '0';
		else
		{
			result = (np == -1) ? 0 : -1;
			break ;
		}
		str++;
	}
	return (result * np);
}

int ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

void print_str(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        write(1, &str[i], 1);
    write(1, "\n", 1);
}

int ft_isnumber(char *num)
{
    int i;
    
    i = -1;
    if (num[0] == '-' || num[0] == '+'){
        i++;
        if (num[i] == '\0')
            return 0;
    }
    while (num[++i])
        if (ft_isdigit(num[i]) == 0)
            return 0;
    return 1;
}

void copy_array(int *dst, int *src, int size)
{
    int i;
    
    i = -1;
    while (++i < size)
        dst[i] = src[i];
}

int ft_strcmp(char *s1, char *s2)
{
	int i;
	
	i = -1;
	while (s1[++i])
		if (s1[i] != s2[i])
			break ;
	return s1[i] - s2[i];
}
