#include "day9.h"

static void	ft_free(char **arr)
{
	int	x;

	x = 0;
	while (arr[x] != NULL)
	{
		free(arr[x]);
		x++;
	}
	free(arr);
}


int main(int argc, char **argv)
{
	int		fd;
	char	**array;
	char	*temp;
	int		rows;
	int		i;

	rows = 0;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	while ((temp = get_next_line(fd)) != NULL)
	{
		free(temp);
		rows++;
	}
	close(fd);
	array = (char **)malloc(sizeof (char *) * (rows + 1));
	if (array == NULL)
		return (1);
	array[rows] = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	while (i < rows)
	{
		array[i] = get_next_line(fd);
		i++;
	}
	close(fd);

	// ir de uno a uno a comparar 
	int		j;
	long	tmp1_r; // row
	long	tmp1_c; // col
	long	tmp2_r;
	long	tmp2_c;
	long	row_s;
	long	col_s;
	long	area;
	long	tmp_area;
	char	 **arr_split;

	i = 0;
	area = 0;
	while (array[i] != NULL)
	{
		arr_split = ft_split(array[i], ',');
		// 0 es la columna y 1 es la fila
		tmp1_r = ft_atol(arr_split[1]);
		tmp1_c = ft_atol(arr_split[0]);
		// tmp1 el que vamos comparar
		ft_free(arr_split);
		j = 1;
		while (array[j] != NULL) // el que vamos a iterar
		{
			arr_split = ft_split(array[j], ',');
			tmp2_r = ft_atol(arr_split[1]);
			tmp2_c = ft_atol(arr_split[0]);
			// tmp1 el que vamos comparar
			ft_free(arr_split);
			
			// Calcular area de los dos puntos
			// 1º Sumar rows y añadir 1
			row_s = tmp2_r - tmp1_r + 1;
			if (row_s < 0)
				row_s = row_s * -1;
			// 2º Sumar cols y añadir 1
			col_s = tmp2_c - tmp1_c + 1;
			if (col_s < 0)
				col_s = col_s * - 1;
			// 3º Multiplicar y encontrar el area -> guardarla en area si es mayor de lo que ya tengo guardado
			tmp_area = row_s * col_s;
			if (tmp_area > area) // mayor o igual???
				area = tmp_area;
			j++;
		}
		i++;
	}
	
	printf("area is %ld\n", area);

	ft_free(array);
	return (0);
}