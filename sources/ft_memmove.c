#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;
	size_t				i;

	dest = dst;
	source = src;
	i = 0;
	if (dest == NULL && source == NULL)
		return (dst);
	if (source < dest)
	{
		while (n-- > 0)
			dest[n] = source[n];
	}
	else
	{
		while (n > i)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}
