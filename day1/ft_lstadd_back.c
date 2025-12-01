#include "day1.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*iter;

	new->next = NULL;
	if (*lst == NULL)
		*lst = new;
	else
	{
		iter = *lst;
		while (iter->next != NULL)
			iter = iter->next;
		iter->next = new;
		new->prev = iter;
	}
}
