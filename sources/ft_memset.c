#include "libft.h"

void	*ft_memset(void *p, int c, size_t len)
{
	unsigned char *a;

	a = p;
	if (!p)
		return (NULL);
	while (len > 0)
	{
		*a++ = c;
		len--;
	}
	return (p);
}
