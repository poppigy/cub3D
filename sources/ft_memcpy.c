#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;
	size_t				i;

	dest = dst;
	source = src;
	i = 0;
	if (dest == NULL && source == NULL)
		return (dst);
	while (n > i)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
