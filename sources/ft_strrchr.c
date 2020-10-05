/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <qcraghas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 17:05:42 by qcraghas          #+#    #+#             */
/*   Updated: 2020/05/22 21:07:07 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*a;

	i = 0;
	if (!s)
		return (NULL);
	a = NULL;
	while (s[i])
	{
		if (s[i] == c)
			a = ((char *)s + i);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		a = ((char *)s + i);
	return (a);
}
