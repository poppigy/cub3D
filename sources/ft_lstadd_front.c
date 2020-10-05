/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <qcraghas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 19:15:22 by qcraghas          #+#    #+#             */
/*   Updated: 2020/05/24 01:07:46 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
