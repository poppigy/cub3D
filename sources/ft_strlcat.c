/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <qcraghas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 15:55:34 by qcraghas          #+#    #+#             */
/*   Updated: 2020/05/22 20:32:27 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	k = 0;
	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (size <= i)
		return (j + size);
	while ((dst[k] != '\0') && k < (size - 1))
		k++;
	while (*src && k < (size - 1))
	{
		dst[k] = *src;
		k++;
		src++;
	}
	dst[k] = '\0';
	return (i + j);
}
