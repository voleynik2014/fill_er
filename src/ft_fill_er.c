
#include "ft_filler.h"

int		ft_filler()
{
	t_fi ller;
	char	**field;
	char	**fig;
	int i;

	ft_bzero(&ller, sizeof(t_fi));
	ft_get_player(&ller);
	field = ft_create_field(&ller);
	fig = ft_create_fig(&ller);
	i = -1;
	while (++i < ller.size_x)
		ft_printf("%s\n", field[i]);
	i = -1;
	while (++i < ller.fig_size_x)
		ft_printf("%s\n", fig[i]);
	return (1);
}

int		main()
{
	ft_filler();
	return (0);
}

