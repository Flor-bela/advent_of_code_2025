#include "day3.h"

int	ft_atoi(char c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if ((c >= '0') && (c <= '9'))
		num = c - '0';
	return (num);
}
