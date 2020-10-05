#include "libft.h"

/*
** Counts the number of elements in a list.
** argv[1]. The beginning of the list.
** Length of the list.
*/

int	ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
