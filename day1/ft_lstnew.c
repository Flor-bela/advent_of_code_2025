#include "day1.h"

t_list	*ft_lstnew(int data)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	if (a == NULL)
		return (NULL);
	a->data = data;
	a->prev = NULL;
	a->next = NULL;
	return (a);
}
