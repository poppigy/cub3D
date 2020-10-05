#include "libft.h"

char	*ft_strtrim(char *s1, char const *set)
{
	char	*trimmed;
	char	*p;
	int		i;

	p = s1;
	if (!s1 || (!s1 && !set))
		return (NULL);
	while (*p && ft_strchr(set, *p))
		p++;
	i = ft_strlen(p);
	while (i > 0 && ft_strchr(set, p[i - 1]))
		i--;
	if (i == 0)
	{
		trimmed = ft_calloc(i, sizeof(char));
		return (trimmed);
	}
	trimmed = ft_substr(p, 0, i);
	return (trimmed);
}
