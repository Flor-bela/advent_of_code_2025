#include "day6.h"
// Didn´t try it yet

int main(int argc, char **argv)
{
	int		fd;
	char	*temp;
	char	**array;
	int		rows;
	int		i;

	rows = 0;
	fd = open(argv[1], O_RDONLY);
	while ((temp = get_next_line(fd)) != NULL)
		rows++;
	close(fd);
	array = (char **)malloc(sizeof (char *) * (rows + 1));
	if (array == NULL)
		return (1);
	array[rows] = NULL;
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i < rows)
	{
		array[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	//printf("Last row value %d\n", i); // last_row (NULL)
	
	int		j;
	int		last_row;
	char	*ptr;
	char	sign;
	long	num;
	long	result_s;
	long	final_result;
	long	result_m;

	last_row = i - 1;
	final_result = 0;
	result_s = 0;
	result_m = 1;
	i = 0;
	j = 1;

	while (array[last_row][i] != '\0')
	{
		//cuando llegue al final de la columna sumo ese valor a lo que tenia ya
		final_result = final_result + result_s;
		if (result_m != 1)
			final_result = final_result + result_m;
		result_s = 0;
		result_m = 1;
		j = 1;
		while (array[last_row][i] == ' ')
			i++; // aqui consigo si es multiplicacion o suma
		sign = array[last_row][i];
		if (sign != '+' && sign != '*')
			break;
		while (last_row - j >= 0)
		{ 
			ptr = &array[last_row - j][i];
			num = ft_atol(ptr);
			if (sign == '+')
			{
				result_s = num + result_s;
				//printf("result_s %ld\n", result_s);
			}
			else if (sign == '*')
			{
				result_m = num * result_m;
				//printf("result_m %ld\n", result_m);
			}
			j++;
		}
		i++;
	}	
	
	printf("Final result %ld\n", final_result);

	// este i es donde tengo que buscar los numeros en las rows anteriores
	
	//printf("value %c\n", array[last_row - j][i]);
	
	//ptr = &array[last_row - j][3];
	//printf("num %s\n", ptr);
	//while (array[last_row - j][i] )
	//printf("num %d\n", ft_atoi(array[last_row - j]));
	
	/* while (last_row - j >= 0)
	{
		array[last_row - j][i]
		j++;
	}
 */
	return(0);
}