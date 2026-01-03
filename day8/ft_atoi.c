#include "day8.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		num = num * 10;
		num = num + nptr[i] - '0';
		i++;
	}
	return (num);
}
