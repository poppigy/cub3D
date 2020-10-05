#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t slen;

	slen = 0;
	i = 0;
	if (!dst)
		return (slen);
	while (src[slen])
		slen++;
	if (!size)
		return (slen);
	while (size > i && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}
