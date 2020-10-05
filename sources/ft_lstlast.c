/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <qcraghas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 21:01:18 by qcraghas          #+#    #+#             */
/*   Updated: 2020/05/24 04:01:00 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** argv[1]. The beginning of the list.
** RETURN: Last element of the list.
** Returns the last element of the list.
*/

t_list	*ft_lstlast(t_list *lst)
{
	t_list *search;

	search = lst;
	while (search)
	{
		if (search->next == NULL)
			return (search);
		search = search->next;
	}
	return (search);
}
