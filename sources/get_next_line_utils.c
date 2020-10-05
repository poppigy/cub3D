#include "libft.h"

int		find_next_line(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

size_t	line_len(char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

size_t	buffsize(char *buff)
{
	size_t i;

	if (!buff)
		return (0);
	i = 0;
	while (buff[i] != '\0')
		i++;
	return (i);
}
