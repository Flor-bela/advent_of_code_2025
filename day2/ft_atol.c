#include "day2.h"

static void	ft_error(void)
{
	write(2, "Error in f_atol\n", 17);
	exit (1);
}

static void	check_sign(const char *nptr, long long *sign, int *i)
{
	if (nptr[*i] == '-')
		*sign = -1;
	if (nptr[*i + 1] == '\0')
		ft_error();
	(*i)++;
}

long long	ft_atol(const char *nptr)
{
	int		i;
	int		j;
	long long	sign;
	long long	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
		check_sign(nptr, &sign, &i);
	j = i;
	while (nptr[i] != '\0')
	{
		if (!((nptr[i] >= '0') && (nptr[i] <= '9')))
			ft_error();
		i++;
	}
	i = j;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
		num = num * 10 + nptr[i++] - '0';
	if (num * sign < LLONG_MIN || num * sign > LLONG_MAX)
		ft_error();
	return (num * sign);
}
