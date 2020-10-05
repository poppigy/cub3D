#include "libft.h"

/*
** Adds the element ’new’ at the beginning of the list.
** argv[1]. The address of a pointer to the first link of a list.
** argv[2]. The address of a pointer to the element to be added to the list.
** RETURN void.
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list *add_new;

	add_new = new;
	add_new->next = *lst;
	*lst = add_new;
}
