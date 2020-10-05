/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <qcraghas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 18:21:22 by qcraghas          #+#    #+#             */
/*   Updated: 2020/05/22 19:43:06 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int c, size_t len)
{
	unsigned char *a;

	a = p;
	if (!p)
		return (NULL);
	while (len > 0)
	{
		*a++ = c;
		len--;
	}
	return (p);
}
