#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*strmapi;

	i = 0;
	j = ft_strlen(s);
	if (!s)
		return (NULL);
	strmapi = ft_calloc(j + 1, sizeof(char));
	if (!strmapi)
		return (NULL);
	while (s[i])
	{
		strmapi[i] = f(i, s[i]);
		i++;
	}
	return (strmapi);
}
