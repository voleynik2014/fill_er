
#include "ft_filler.h"

int		ft_filler_start(void)
{
	t_fi ller;
	char	**field;
	char	**fig;
	int i;

//		ft_printf("1floor");
	ft_bzero(&ller, sizeof(t_fi));
	ller.f = fopen("file.txt", "a");
	fprintf(ller.f, "st");
	ft_get_player(&ller);
	while (1)
	{
		field = ft_create_field(&ller);
//		sleep(999);
		fclose(ller.f);
		fig = ft_create_fig(&ller);
		fprintf(ller.f, "ok");
		ft_filler(fig , field, &ller);
		i = -1;
//		return (0);
//		sleep(99);
/*		while (++i < ller.size_x)
			ft_printf("%s\n", field[i]);
		i = -1;
		while (++i < ller.fig_size_x)
			ft_printf("%s\n", fig[i]);
*/		ft_printf("%d %d\n", ller.res_x, ller.res_y);
//		ft_printf("%d %d", ller.size_x, ller.size_y);
		free(field);
		free(fig);
		ft_bzero(&ller, sizeof(t_fi));
		}
	return (1);
}

int		main()
{
//	ft_printf("2floor");
	ft_filler_start();
	return (0);
}
