#include "day1.h"

int	main(int argc, char **argv)
{
	int i;
	char	*str;
	int	counter;
	int	value;
	int fd;
	t_list	*lst;
	t_list	*last;
	t_list	*temp;
	
	i = 0;
	counter = 0;
	lst = NULL;
	fd = open(argv[1], O_RDONLY);
	while (i < 100)
	{
		temp = ft_lstnew(i);
		ft_lstadd_back(&lst, temp);
		i++;
	}
	last = ft_lstlast(lst);
	last->next = lst;
	lst->prev  = last;

	i = 50;
	while (i > 0) //head of list needs to start at 50
	{
		lst = lst->next;
		i--;
	}
	while (42)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		if (str[0] == 'L')
		{	
			value = ft_atoi(str + 1);
			while (value > 0)
			{
				lst = lst->prev;
				value--;
			}
			if (lst->data == 0)
					counter++;
		}
		else if (str[0] == 'R')
		{	
			value = ft_atoi(str + 1);
			while (value > 0)
			{
				lst = lst->next;
				value--;
			}
			if (lst->data == 0)
					counter++;
		}
		free(str);
	}
	printf("%d\n", counter);
	return (0);
}