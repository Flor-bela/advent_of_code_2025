#include "day8.h"

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
		rows++;
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
	// Crear otra matriz para guardar las coordenadas X Y y Z con 4 columnas en que la ultima es la Box ID
	
	char	**arr1; // para guardar las distancias euclideanas del punto 1
	arr1 = (char **)malloc(sizeof (char *) * (rows + 1));
	if (arr1 == NULL)
		return (1);
	arr1[rows] = NULL; // aqui va a ser hasta el numero en que estamos 

	char	**arr1_tmp;
	char	**arr2_tmp;
	int 	tmp;
	
	// LOOP
	i = 0;
	while (i + 1 < rows)
	{
		arr1_tmp = ft_split(array[i], ',');
		arr2_tmp = ft_split(array[i + 1], ','); // i es el que va avanzando en el loop hasta que llegue al ultimo valor.
			
		tmp = (ft_atoi(arr2_tmp[0]) - ft_atoi(arr1_tmp[0])) * (ft_atoi(arr2_tmp[0]) - ft_atoi(arr1_tmp[0])) 
		+ (ft_atoi(arr2_tmp[1]) - ft_atoi(arr1_tmp[1])) * (ft_atoi(arr2_tmp[1]) - ft_atoi(arr1_tmp[1])) 
		+ (ft_atoi(arr2_tmp[2]) - ft_atoi(arr1_tmp[2])) * (ft_atoi(arr2_tmp[2]) - ft_atoi(arr1_tmp[2]));

		arr1[i] = ft_itoa(tmp);
		i++;
	}
	printf("arr 1 %s\n", arr1[0]);
	

	i = 0;
	while (array[i] != NULL)
	{	
		free(array[i]);
		i++;
	}
	free(array);
	i = 0;
	while (arr1_tmp[i] != NULL)
	{	
		free(arr1_tmp[i]);
		i++;
	}
	free(arr1_tmp);
	i = 0;
	while (arr2_tmp[i] != NULL)
	{	
		free(arr2_tmp[i]);
		i++;
	}
	free(arr2_tmp);

	return (0);
}