#include "day4.h"

int	main(int argc, char **argv)
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
		rows++;
		free(temp);
	}
	close(fd);
	printf("rows %d\n", rows);
	array = (char **)malloc(sizeof(char *) * (rows + 1));
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
 
	char	**cp_array;
	cp_array = (char **)malloc(sizeof(char *) * (rows + 1));
	if (cp_array == NULL)
		return (1);
	cp_array[rows] = NULL;
	i = 0;
	while (i < rows)
	{
		cp_array[i] = ft_strdup(array[i]);
		i++;
	}
	
	// check the adjacent cells
	int	cols;
	int	j;
	int	counter;
	int	flag;
	
	cols = ft_strlen(array[0]);
	i = 0;
	flag = 0;
		// tengo que hacer este loop varias veces: poner loop infinito con break
	while (1)
	{
		i = 0;
		flag = 0;
		while (array[i] != NULL)
		{
			j = 0;
			while (array[i][j] != '\0')
			{
				counter = 0;
				if ((i - 1 >= 0) && (array[i - 1][j] == '@'))	//1 row arriba NO
					counter++;
				if ((i + 1 < rows) && (array[i + 1][j] == '@'))   //1 row abajo 
					counter++;
				if ((j + 1 < cols) && (array[i][j + 1] == '@'))   //1 col a la derecha
					counter++;
				if ((j - 1 >= 0) && (array[i][j - 1] == '@'))   //1 col a la izquierda
					counter++;

				// diagonals:
				if ((i - 1 >= 0) && (j - 1 >= 0) && (array[i - 1][j - 1] == '@'))   //1 diagonal arriba izquierda
					counter++;
				if ((i - 1 >= 0) && (j + 1 < cols) && (array[i - 1][j + 1] == '@'))   //1 diagonal arriba derecha
					counter++;
				if ((i + 1 < rows) && (j + 1 < cols) && (array[i + 1][j + 1] == '@'))   //1 diagonal abajo derecha
					counter++;
				if ((i + 1 < rows) && (j - 1 >= 0) && (array[i + 1][j - 1] == '@'))   //1 diagonal abajo izquierda
					counter++;
				
				if (counter < 4 && array[i][j] == '@')
				{
					cp_array[i][j] = 'x';
					flag = 1; // si nunca cambia nada entonces parar
				}
				j++;
			}
			i++;
			int z;
			z = 0;
			while (z < rows) // actualizar tanto array como cp_array para los proximos loops
			{
				array[z] = ft_strdup(cp_array[z]);
				z++;
			}
			z = 0;
			while (z < rows)
			{
				cp_array[z] = ft_strdup(array[z]);
				z++;
			}
		}
		if (flag == 0)
			//goto jump_here; //this is the same as break here!
			break;
	}
	
	//jump_here:
	i = 0;
	counter = 0;
	while(cp_array[i] != NULL)
	{
		j = 0;
		while (cp_array[i][j] != '\0')
		{
			if (cp_array[i][j] == 'x')
				counter++;
			j++;
		}
		i++;
	}
	printf("The rolls of paper that can be accessed are %d\n", counter);

	 
	//FREE CP_ARRAY y ARRAY
	return (0);
}