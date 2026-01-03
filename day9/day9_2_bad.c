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
static void	ft_draw_map(char **map, char **array)
{
	int		i;
	long	tmp_r;
	long	tmp_c;
	char	**arr_tmp;

	i = 0;
	while (array[i] != NULL)
	{
		arr_tmp = ft_split(array[i], ',');
		tmp_r = ft_atol(arr_tmp[1]);
		tmp_c = ft_atol(arr_tmp[0]);
		map[tmp_r][tmp_c] = '#';
		ft_free(arr_tmp);
		i++;
	}
	i = 0;
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
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
	// Vamos a dibujar el mapa
	// Ver el numero más grande de rows y de cols
	i = 0;
	long	tmp_r;;
	long	tmp_c;
	char	**arr_tmp;
	long	max_row;
	long	max_col;

	max_row = 0;
	max_col = 0;
	while (array[i] != NULL)
	{
		arr_tmp = ft_split(array[i], ',');
		tmp_r = ft_atol(arr_tmp[1]);
		tmp_c = ft_atol(arr_tmp[0]);
		if (tmp_r > max_row)
			max_row = tmp_r;
		if (tmp_c > max_col)
			max_col = tmp_c;
		i++;
		free(arr_tmp);
	}
	//printf("Max row is %ld\n", max_row);
	//printf("Max col is %ld\n", max_col);

	// Dibujar el mapa
	int j;
	char	**map;

	max_row = max_row + 1; // to consider 0 and the NULL row
	map = (char **)malloc(sizeof(char *) * (max_row + 1));
	if (map == NULL)
	{
		free(array);
		return (1);
	}
	map[max_row] = NULL;
	i = 0;
	j = 0;
	max_col = max_col + 1; // to include 0 as a position too
	while (i < max_row)
	{
		map[i] = (char *)malloc(sizeof(char *) * (max_col + 1));
		if (map[i] == NULL)
		{
			ft_free(array);
			return (1);
		}
		j = 0;
		while (j < max_col)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	ft_draw_map(map, array); // Need to print # on their respective places

	ft_free(array);
	ft_free(map);
	return (0);
}