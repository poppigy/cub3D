/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <qcraghas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:00:03 by qcraghas          #+#    #+#             */
/*   Updated: 2020/05/24 01:15:19 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;
	unsigned	char	d;
	size_t				i;

	d = c;
	dest = dst;
	source = src;
	i = 0;
	if (dest == NULL || source == NULL)
		return (NULL);
	while (n > i)
	{
		dest[i] = source[i];
		if (source[i] == d)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
