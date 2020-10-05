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
