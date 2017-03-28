#include "ft_filler.h"

int 	ft_get_player(t_fi *ller)
{
	char *src;

	get_next_line(0, &src);
	if (ft_strcmp(src, "$$$ exec p"))
		ller->pl = src[10] - '0';
	return (0);
}

char		**ft_create_field(t_fi *ller)
{
	char	*src;
	char	**arr;
	int		i;

	get_next_line(0, &src);
	if (ft_strcmp(src, "Plateau "))
	{
		arr = ft_strsplit(src + 8, ' ');
		free(src);
		i = 0;
		while (ft_isdigit(arr[0][i]))
			ller->size_x = ller->size_x * 10 + (arr[0][i++] - '0');
		i = 0;
		while (ft_isdigit(arr[1][i]))
			ller->size_y = ller->size_y * 10 + (arr[1][i++] - '0');
		free(arr);
	}
	arr = (char **)malloc(sizeof(char *) * ller->size_x + 1);
	get_next_line(0, &src);
	i = -1;
	while (++i < ller->size_x)
	{
		get_next_line(0, &src);
		arr[i] = ft_strdup(src + 4);
	}
	arr[i] = NULL;
	return (arr);
}

char		**ft_create_fig(t_fi *ller)
{
	char	*src;
	char	**arr;
	int		i;

	arr = NULL;
	get_next_line(0, &src);
	if (ft_strcmp(src, "Piece"))
	{
		arr = ft_strsplit(src + 6, ' ');
		i = -1;
		i = 0;
		while (ft_isdigit(arr[0][i]))
			ller->fig_size_x = ller->fig_size_x * 10 + (arr[0][i++] - '0');
		i = 0;
		while (ft_isdigit(arr[1][i]))
			ller->fig_size_y = ller->fig_size_y * 10 + (arr[1][i++] - '0');
		free(arr);
	}
	arr = (char **)malloc(sizeof(char *) * ller->fig_size_x + 1);
	i = -1;
	while (++i < ller->fig_size_x)
		get_next_line(0, &arr[i]);
	arr[i] = NULL;
	return (arr);
}
