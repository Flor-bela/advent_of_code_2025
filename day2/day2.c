#include "day2.h"

static void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	main (int argc, char **argv)
{
	char	**array;
	char	**array2;
	char	**temp;
	char	*input;
	int		i;
	int		j;
	int		fd;
	int		temp_1;
	int		temp_2;
	int		half;
	char	*temp1;
	char	*temp2;
	long long	num1;
	long long	num2;
	long long	tmp1;
	long long	tmp2;
	long long	count;
	
	i = 0;
	count = 0;
	fd = open(argv[1], O_RDONLY);
	input = get_next_line(fd);
	if (fd < 0)
		return (1);
	close (fd);
	array = ft_split(input, ',');
	if (array == NULL)
		return (1);
	while (array[i] != NULL)
		i++;
	j = i * 2; 
	array2 = (char **)malloc(sizeof(char *) * (j + 1));
	if (array2 == NULL)
	{
		free(array);
		return (1);
	}	
	array2[j] = NULL;
	i = 0;
	j = 0;
	while (array[i] != NULL)
	{
		temp = ft_split(array[i], '-');
		if (temp == NULL)
		{
			free(array);
			free(array2);
			return (1);
		}
		array2[j] = temp[0];
		array2[j + 1] = temp[1];
		i++;
		j+=2;
	}
	j = 0;
	i = 0;
	while (array2[i] != NULL && array2[i + 1] != NULL)
	{
		num1 = ft_atol(array2[i]);
		num2 = ft_atol(array2[i + 1]);
		
		// Check how many digits and if they are even 
		while (num1 <= num2)
		{
			temp_1 = ft_strlen(array2[i]);
			if (temp_1 % 2 == 0)  // it´s an even numnber
			{
				half = temp_1 / 2;
				temp1 = ft_substr(array2[i], 0, half);
				if (temp1 == NULL)
			/* 	{
					free(array);
					free(array2);
					free(temp);
				} */
				temp2 = ft_substr(array2[i], half, half);
				/* {
					free(array);
					free(array2);
					free(temp);
					free(temp1);
				} */
				tmp1 = ft_atol(temp1);
				tmp2 = ft_atol(temp2);
				if (tmp1 == tmp2)
					count = count + num1;
			}
			num1++;
			array2[i] = ft_ltoa(num1);
		}
		i += 2;
	}
	printf("The result is %lld\n", count);

	free(array);
	free(array2);
	free(temp);
	free(temp1);
	free(temp2);
	return (0);
}