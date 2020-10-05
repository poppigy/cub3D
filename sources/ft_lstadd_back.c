#include "libft.h"

/*
** argv[1]. The address of a pointer to the first link of a list.
** argv[2]. The address of a pointer to the element to be added to the list.
** RETURN: void.
** Adds the element ’new’ at the end of the list.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *a;

	a = *lst;
	if (!new)
		ft_lstclean(lst);
	else
	{
		if (a)
		{
			while (a->next)
				a = a->next;
			a->next = new;
		}
		else
			*lst = new;
	}
}
