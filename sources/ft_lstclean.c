#include "libft.h"

void	ft_lstclean(t_list **lst)
{
	t_list *a;

	a = *lst;
	while (a)
	{
		if (*lst)
			*lst = (*lst)->next;
		free(a);
		a = *lst;
	}
}
