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
