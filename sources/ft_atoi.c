#include "libft.h"

static int	check_rgb_trash(char *s)
{
	while (*s != '\0')
	{
		if (*s != ' ')
			return (0);
		s++;
	}
	return (1);
}

int			ft_atoi(const char *str)
{
	int atoi;
	int sign;
	int check;

	check = 0;
	sign = 1;
	atoi = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = *str == '-' ? -1 : 1;
		str++;
	}
	while ((*str >= '0' && *str <= '9') && *str != '\0')
	{
		atoi = atoi * 10 + *str - 48;
		str++;
		check++;
		if (atoi < 0)
			return (10000);
	}
	if (!check_rgb_trash((char *)str) || check == 0)
		return (-1);
	return (atoi * sign);
}
