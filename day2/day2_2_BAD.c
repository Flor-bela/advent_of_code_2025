#include "day2.h"

int	main (int argc, char **argv)
{
	char	**array;
	char	**array2;
	char	**temp;
	long long	num1;
	long long	num2;
	char	*input;
	int		i;
	int		j;
	int		fd;
	int		temp_1;
	int		temp_2;
	int		half;
	char	*temp1;
	char	*temp2;
	long long	count;
	long long	temp_count;
	int	mod;
	
	i = 0;
	count = 0;
	fd = open(argv[1], O_RDONLY);
	input = get_next_line(fd);
	array = ft_split(input, ',');
	while (array[i] != NULL)
		i++;
	j = i * 2; 
	array2 = (char **)malloc(sizeof(char *) * (j + 1));
	array2[j] = NULL;
	i = 0;
	j = 0;
	while (array[i] != NULL)
	{
		temp = ft_split(array[i], '-');
		array2[j] = temp[0];
		array2[j + 1] = temp[1];
		i++;
		j+=2;
	}
	printf("array2 %s\n", array2[0]); 
	printf("array2 %s\n", array2[1]); 
	j = 0;
	i = 0;
	while (array2[i] != NULL && array2[i + 1] != NULL)
	{
		num1 = ft_atol(array2[i]);
		num2 = ft_atol(array2[i + 1]);
		/* temp_1 = ft_strlen(array2[i]);
		temp_2 = ft_strlen(array2[i + 1]); */
		//printf("temp 1 %d\n", temp_1);
		// ver cuantos digitos tiene y si son pares avanzar
		while (num1 <= num2) // > y = tal vez?
		{
			temp_1 = ft_strlen(array2[i]);
			if (temp_1 % 2 == 0)  // es par
			{
				long long	tmp1;
				long long	tmp2;
				//tmp1 = ft_atol(temp1);
				//tmp2 = ft_atol(temp2);
				mod = temp_1 - 1; 
				while (mod > 0) // no incluyo 0
				{
					tmp1 = ft_atol(temp1);
					tmp2 = ft_atol(temp2);
					if (tmp1 % mod == 0) //UFFF vaya locura....modulo y tenía que definir dividir cada porcion del digito por los conjuntos
					{
						temp1 = ft_substr(array2[i], 0, mod);
						temp2 = ft_substr(array2[i], half, half);
						long long	tmp1;
						long long	tmp2;
						tmp1 = ft_atol(temp1);
						tmp2 = ft_atol(temp2);
					}
						if (tmp1 == tmp2)
					{
					//printf("tmp1 %lld\n", tmp1);
					//printf("tmp2 %lld\n", tmp2);
						count = count + num1;
					//printf("count is %lld\n", count);
					}
					mod--;
				}
			}
			num1++;
			array2[i] = ft_ltoa(num1);
		}
		i += 2;
	}
	printf("count is %lld\n", count);

	//free de los arrays
	return (0);
}