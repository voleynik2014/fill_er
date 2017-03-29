
#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include "../libft/libft.h"

typedef struct 	s_fi
{
	int 		pl;
	int			size_x;
	int			size_y;
	int			fig_size_x;
	int			fig_size_y;
	int			x;
	int			y;
	int			res_x;
	int			res_y;
}				t_fi;

int				ft_get_player(t_fi *ller);
char			**ft_create_field(t_fi *ller);
char			**ft_create_fig(t_fi *ller);
void			ft_filler(char **shape, char **field, t_fi *ller);

#endif
