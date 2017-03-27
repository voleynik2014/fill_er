#include "ft_filler.h"

int 	ft_get_player(t_fi *ller)
{
	char *src;
	char *point;

	ller->num = 0;
	while (get_next_line(0, &src))
	{
		if (ft_strcmp(src, "$$$ exec p"))
			point = src + 10;
	}
	ft_printf("%s", point);
	return (0);
}
