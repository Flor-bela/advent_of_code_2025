#include "day5.h"

long	ft_atol(const char *nptr)
{
	int	i;
	int	sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		num = num * 10;
		num = num + nptr[i] - '0';
		i++;
	}
	return (sign * num);
}
