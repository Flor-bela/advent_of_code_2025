#include "day5.h"

int	main(int argc, char **argv)
{
	int	fd;
	char **array;
	char **array_cp;
	char *temp;
	int	rows;
	int	i;

	i = 0;
	rows = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	while ((temp = get_next_line(fd)) != NULL)
		rows++;
	close(fd);
	array = (char **)malloc(sizeof(char *) * (rows + 1));
	if (array == NULL)
		return (1);
	fd = open(argv[1], O_RDONLY);
	while(i < rows)
	{
		array[i] = get_next_line(fd);
		i++;
	}
	array[rows] = NULL;
	close(fd);
	array_cp = (char **)malloc(sizeof(char *) * (rows + 1));
	if (array_cp == NULL)
		return (1);
	fd = open(argv[1], O_RDONLY);
	while(i < rows)
	{
		array_cp[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	// To know until where I have the ranges and when the IDs start
	/* i = 0;
	while (i < rows)
	{
		if (array[i][0] == '\n')
			break ;
		i++;
	} */
	char **range;
	long	temp1;
	long	temp2;
	int	counter;
	int	j;
	
	i = 0;
	j = 0;
	counter = 0;
	while (array_cp[j][0] != '\n') // Necesitaria poder ver que el range que tengo no entra en ningun otro
	{
		i = 0;
		while (array[i][0] != '\n')
		{
			range = ft_split(array[i], '-');
			temp1 = ft_atol(range[0]);
			temp2 = ft_atol(range[1]);
			if (temp2 - temp1 != 0)
			{
				while(temp1 < temp2)
				{
					temp1++;
					counter++;
				}	
			}
			if (temp2 - temp1 == 0)
				counter++; // only count temp1 and temp2
			free(range[0]);
			free(range[1]);
			free(range);
			i++;
		}
		j++
	}
	printf("counter %d\n", counter);
	// ahora crear otro array para poner los ids solamente Y hago free en el array con todo.
	/* int	first_id_row = i + 1;  // la fila después del salto de línea
	int ids_rows = rows - first_id_row;
 */
	//printf("ids_rows is %d\n", ids_rows);
	/* array_ids = (char **)malloc(sizeof (char *) * (ids_rows + 1));
	if (array_ids == NULL)
		return (1);
	array_ids[ids_rows] = NULL;
	int	j;
	j = 0;
	i = 0;
	while (i < ids_rows)
	{
		array_ids[i] = ft_strdup(array[first_id_row + i]);
		i++;
	} */
	//printf("array_ids[0] = %s\n", array_ids[0]);
	//printf("i is %d\n", i);
	//printf("array_ids[0] = %s\n", array_ids[1000]);
	//printf("array_ids[0] = %s\n", array_ids[1001]);
	/* 
	char	**range;
	long	temp1;
	long	temp2;
	long	temp_id;
	int		counter;
	int		found;

	counter = 0;
	j = 0;
	while (array_ids[j] != NULL)
	{
		i = 0;
		found = 0;
		temp_id = ft_atol(array_ids[j]);
		while (array[i][0] != '\n')
		{
			range = ft_split(array[i], '-');
			temp1 = ft_atol(range[0]);
			temp2 = ft_atol(range[1]);
			if (temp_id > temp1 && temp_id < temp2 || temp_id == temp1 || temp_id == temp2)
			{
				found = 1;
			}
			free(range[0]);
			free(range[1]);
			free(range);
			i++;
		}
		if (found == 1)
			counter++;
		j++;
	}
	printf("counter is %d\n", counter);
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	i = 0;
	while (array_ids[i] != NULL)
	{
		free(array_ids[i]);
		i++;
	}
	free(array_ids); */
	return (0);
}