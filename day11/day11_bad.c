#include "day11.h"

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
	
	int j;

	i = 0;
	j = 0;
	// We find the start position
	while (array[i] != NULL)
	{
		if (array[i][0] == 'y' && array[i][1] == 'o' && array[i][2] == 'u')
			printf("we start here: %d\n", i); // minus one because it starts in 0
		i++;
	}
	// Now we can start
	j = 5;
	//ft_strncmp.... algo así
	while (array[i] != NULL)
	{
		
	}
 
	
	ft_free(array);
	return (0);
}