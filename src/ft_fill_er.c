
#include "ft_filler.h"

int		ft_filler_start(void)
{
	t_fi ller;
	char	**field;
	char	**fig;
	int i;

	ft_bzero(&ller, sizeof(t_fi));
	//sleep(999);
	ft_get_player(&ller);
	field = ft_create_field(&ller);
	fig = ft_create_fig(&ller);
	ft_filler(fig , field, &ller);
	i = -1;
//	return (0);
//	sleep(99);
/*	while (++i < ller.size_x)
		ft_printf("%s\n", field[i]);
	i = -1;
	while (++i < ller.fig_size_x)
		ft_printf("%s\n", fig[i]);
*/	ft_printf("%d %d", ller.x, ller.y);
	ft_printf("%d %d", ller.size_x, ller.size_y);
	return (1);
}

int		main()
{
	ft_filler_start();
	return (0);
}
