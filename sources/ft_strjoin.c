/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <qcraghas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:03:05 by qcraghas          #+#    #+#             */
/*   Updated: 2020/05/22 19:41:37 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	char	*sj;

	i = 0;
	if (!s1 || (!s1 && !s2))
		return (NULL);
	sj = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (sj == NULL)
		return (NULL);
	while (*s1)
	{
		sj[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		sj[i] = *s2++;
		i++;
	}
	sj[i] = '\0';
	return (sj);
}
