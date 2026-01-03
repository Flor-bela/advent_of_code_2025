#include "day10.h"

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
	
	int	j;
	int	counter;

	j = 0;
	counter = 0;
	while (array[0][j] != '\0')
	{
		if (array[0][j] == '[')
		{
			j++;
			while (array[0][j] != ']')
			{
				counter++;
				j++;
			}
		}
		j++;
	}

	printf("array 0 %s\n", array[0]);
	printf("counter %d\n", counter);

	ft_free(array);
	return (0);
}