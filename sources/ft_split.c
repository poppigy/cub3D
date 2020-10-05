/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <qcraghas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 16:53:16 by qcraghas          #+#    #+#             */
/*   Updated: 2020/05/26 13:38:05 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	count;

	count = 1;
	while (*s)
	{
		if (*s == c)
		{
			count++;
			while (*s && *s == c)
				s++;
		}
		else
		{
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*ft_word_malloc(const char *s, char c)
{
	int		i;
	char	*word_malloc;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word_malloc = ft_calloc(i + 1, sizeof(char));
	if (word_malloc == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word_malloc[i] = s[i];
		i++;
	}
	return (word_malloc);
}

static char	**ft_free_split(char **split, int i)
{
	while (i-- >= 0)
		free(split[i]);
	free(split);
	return (split);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**split;

	i = 0;
	if (!s)
		return (NULL);
	words = ft_word_count(s, c);
	if (!(split = (char**)ft_calloc(words + 1, sizeof(char*))))
		return (NULL);
	while (*s && i < words)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			split[i] = ft_word_malloc(s, c);
			if (split[i] == NULL)
				return (ft_free_split(split, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (split);
}
