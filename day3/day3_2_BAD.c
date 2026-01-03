#include "day3.h"

int	main(int argc, char **argv)
{
	int	fd;
	int	lines;
	int	i;
	char **array;
	char *temp;

	lines = 0;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	while ((temp = get_next_line(fd)) != NULL)
	{
		lines++;
		free(temp);
	}
	close (fd); // y despues open again
	array = (char **)malloc(sizeof(char *) * (lines + 1));
	/* if (array == NULL)
		return (1); */
	array[lines] = NULL;
	fd = open(argv[1], O_RDONLY); // open again 
	if (fd < 0)
		return (1);
	while (i < lines)
	{
		array[i] = get_next_line(fd);
		i++;
	}
	
	int	len_array;
	int	len;
	int	temp1;
	int	temp2;
	int num_final;
	int	counter;
	int	j;
	int z;
	int flag;
	
	len_array = i; // len array
	counter = 0;
	i = 0;
	
	while (i < len_array)
	{
		j = 1;
		z = 1;
		flag = 0;
		num_final = 0;
		len = ft_strlen(array[i]);
		// For the first digit:
		temp1 = ft_atoi(array[i][0]);
		while (j < len - 2) // to not count last digit and null character
		{
			if ((ft_atoi(array[i][j])) > temp1)
			{	
				temp1 = ft_atoi(array[i][j]); // the highest value at the left and it's position in j
				z = j; // if no digit is bigger, no z is set.
				flag = 1;
			}
			j++;
		}
		printf("flag %d\n", flag);
		printf("temp1 %d\n", temp1);
		// j will be already the number after the highest we found so we continue from its position
		// For the second digit
		if (flag == 1)
			z++; // flag in case I need to add another number...
		temp2 = ft_atoi(array[i][z]);
		printf("temp 2 %d\n", temp2);
		z++;
		while (z < len - 1) // if j already is the last number then we won´t enter here and that means temp2 is already the number we were looking for
		{
			if (ft_atoi(array[i][z]) > temp2)
				temp2 = ft_atoi(array[i][z]);
			z++;
		}
		// Now we should have the two digits
		num_final = temp1;
		num_final = num_final * 10;
		num_final = num_final + temp2;
		printf("num final %d\n", num_final);
		counter = counter + num_final;
		i++;
	}
	printf("counter is %d", counter);
	return (0);
}