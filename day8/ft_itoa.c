#include "day8.h"

char	*ft_itoa(int nbr)
{
	char	*str;
	int		i;
	int		size;
	int		sign;
	int		temp;

	sign = 0;
	size = 0; // se me había olvidado inicializar esta variable... y con mis tests funcionaba pero parece que el test del examen no!!!
	if (nbr == 0) // si es 0
	{
		str = (char *)malloc(sizeof (char *) * 1 + 1);
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	} //
	if (nbr < 0)
	{
		sign = 1;
		nbr = nbr * (-1); // pasarlo a positivo (esto me podría dar un problema con INT_MIN!!!)
	}
	i = 0;
	temp = nbr;
	while (temp != 0)
	{
		temp = temp / 10;
		size++; // así sabré cuantas veces ha dividido y sabré cuantos digitos tiene
	}
	str = (char *)malloc(sizeof (char *) * size + sign + 1);
	if (str == NULL)
		return (NULL);
	if (sign == 1)
		i = size;
	else
		i = size - 1;
	while (nbr != 0)
	{
		temp = nbr % 10;
		if (temp >= 0 && temp <= 9)
		{
			str[i] = temp + '0';
			i--;
		}
		nbr = nbr / 10;
	}
	if (sign == 1)
	{
		str[0] = '-';
		str[size + 1] = '\0';
	}
	else
		str[size] = '\0';
	return (str);
}

/* int	main(void)
{
	int		num;
	char	*c;
	
	num = 26;
	c = ft_itoa(num);
	printf("C is %s\n", c);
	free (c);
	return (0);
} */
