#include "cub3d.h"

char	*add_empty(int len)
{
	char	*empty;
	int		i;

	i = 0;
	if (!(empty = (char *)malloc(sizeof(char) * (len + 1))))
		exit(ft_errors(ERR_MALLOC));
	while (i < len)
		empty[i++] = ' ';
	empty[i] = '\0';
	return (empty);
}

char	**map_make(t_list **map, int len)
{
	int		i;
	int		j;
	t_list	*t;
	char	**map_array;

	t = *map;
	i = ft_lstsize(t);
	j = 1;
	if (!(map_array = (char **)ft_calloc(i + 3, sizeof(char *))))
		exit(ft_errors(ERR_MALLOC));
	*map_array = add_empty(len);
	while (t)
	{
		map_array[j] = t->content;
		t = t->next;
		j++;
	}
	map_array[j] = add_empty(len);
	ft_lstclean(map);
	return (map_array);
}

char	*map_add(char *content, int c)
{
	char	*t;
	int		i;

	t = content;
	if (!(content = (char *)ft_calloc(1, sizeof(char) * (c + 1))))
		exit(ft_errors(ERR_MALLOC));
	i = -1;
	while (t[++i] != '\0')
		content[i] = t[i];
	c -= ft_strlen(t);
	while (c-- > 0)
		content[i++] = ' ';
	free(t);
	return (content);
}

void	map_fill(t_list **map, size_t len)
{
	t_list *tmp;

	tmp = *map;
	while (tmp)
	{
		if (ft_strlen(tmp->content) < len)
			tmp->content = map_add(tmp->content, len);
		tmp = tmp->next;
	}
}
