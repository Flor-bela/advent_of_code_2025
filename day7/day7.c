#include "day7.h"

int main(int argc, char **argv)
{
	int		fd;
	char	*temp;
	char	**array;
	int		rows;
	int		i;
	int		j;

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
	i = 0;
	j = 0;
	while (array[i][j] != '\0')
	{
		if (array[i][j] == 'S') // line [0] here
		{
			i++; // line [1] here
			array[i][j] = '|';
			break ;
		}
		j++;
	}
	i++;
	
	int	counter;
	// i starts at 2!
	while (array[i] != NULL)
	{
		counter = 0;
		j = 0;
		while (array[i][j] != '\n' && array[i][j] != '\0') // line [2] here
		{
			if (array[i][j] == '^')
				counter++;
			j++;
		}
		if (counter == 0)
		{
			j = 0;
			i--; // go back one line and check where the | are
			while (array[i][j] != '\n' && array[i][j] != '\0')
			{
				if (array[i][j] == '|' && array[i + 1] != NULL)
					array[i + 1][j] = '|'; // la linea que estamos en el momento
				j++;
			}
			i++; // go back to the row we where
		}
		if (counter != 0)
		{	// entonces tengo ^ y es facil
			j = 0;
			while (array[i][j] != '\n' && array[i][j] != '\0')
			{
				if ((array[i][j] == '^') && (array[i][j + 1] != '\0') && (array[i][j + 1] != '\n'))
					array[i][j + 1] = '|';
				if ((array[i][j] == '^') && (j - 1 >= 0))
					array[i][j - 1] = '|';
				if (array[i - 1][j] == '|' && array[i][j] != '^') // muy importante esto!!!
					array[i][j] = '|'; // la linea que estamos en el momento
				j++;
			}
		}
		i++;
	}

	// Now count how many times it was split:
	i = 0;
	j = 0;
	counter = 0;
	while (array[i] != NULL)
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			if ((array[i][j] == '^') && (array[i - 1][j] == '|'))
				counter++;
			j++;
		}
		i++;
	}
	printf("Counter is %d\n", counter);
	i = 0;
	while (array[i] != NULL)
	{	
		printf("%s\n", array[i]);
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}
