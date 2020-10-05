/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <qcraghas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 13:53:22 by qcraghas          #+#    #+#             */
/*   Updated: 2020/05/25 16:08:53 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*a;
	size_t			fullsize;

	if (size != 0)
	{
		if (((count * size) / size) != count)
			return (NULL);
	}
	fullsize = count * size;
	a = (unsigned char*)malloc(sizeof(unsigned char) * fullsize);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, fullsize);
	return (a);
}
