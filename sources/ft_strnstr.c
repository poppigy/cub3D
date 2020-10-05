#include "libft.h"

char	*ft_strnstr(const char *s, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (src == NULL || s == NULL)
		return (NULL);
	if (*src == '\0')
		return ((char*)s);
	while (s[j] && j < len)
	{
		i = 0;
		while ((j + i < len) && s[j + i] == src[i] && src[i])
			i++;
		if (!src[i])
			return ((char*)(s + j));
		j++;
	}
	return (NULL);
}
