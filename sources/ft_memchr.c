#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int					i;
	const unsigned char	*t;
	unsigned char		b;

	t = s;
	b = c;
	i = 0;
	while (n-- > 0)
	{
		if (*t == b)
			return ((void*)s + i);
		t++;
		i++;
	}
	return (NULL);
}
