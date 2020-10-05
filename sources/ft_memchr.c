/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <qcraghas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 00:33:19 by qcraghas          #+#    #+#             */
/*   Updated: 2020/05/21 14:56:19 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int					i;
	const unsigned char	*t;
	unsigned char		b;

	t = s;
	b = c;
	i = 0;
	while (n-- > 0)
	{
		if (*t == b)
			return ((void*)s + i);
		t++;
		i++;
	}
	return (NULL);
}
