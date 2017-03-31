/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:58:39 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/29 21:32:31 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		check_insert_shape(char **shape, char **field, t_fi *ller)
{
	int y;
	int x;
	int sym;
	int count;

	if ((ller->fig_size_y + ller->y > ller->size_y) || (ller->fig_size_x + ller->x > ller->size_x))
		return (0);
	sym = ller ? 'X' : 'O';
	count = 0;
	x = -1;
	while (++x < ller->fig_size_x)
	{
		y = -1;
		while (++y < ller->fig_size_y)
		{
			if (shape[x][y] == '*')
			{
				if (field[ller->x + x][ller->y + y] == sym)
				{
					count++;
//					ft_printf("%d %d %d\n", count, ller->x + x, ller->y + y);
//					ft_printf("A%d %dA", ller->x, ller->y);
				}
				else if (field[ller->x + x][ller->y + y] == (sym == 'X' ? 'O' : 'X'))
					return (0);
				else if (field[ller->x + x][ller->y + y] == (sym == 'o' ? 'x' : 'x'))
					return (0);
			}
		}
	}
	return (count == 1 ? 1 : 0);
}

int		ft_test_distance(t_fi *ller, int x2, int y2, int *dist)
{
	int	tmp;

	tmp = ft_squere(x2 - ller->x, 2) + ft_squere(y2 - ller->y, 2);
//	ft_printf("OK\n");
	if (tmp < (*dist))
	{
		ller->res_x = ller->x;
		ller->res_y = ller->y;
		(*dist) = tmp;
	}
	return (1);
}

void	ft_my_xy_to_cont_xy(t_fi *ller, char **field, int *dist)
{
	int x_cont;
	int	y_cont;

	x_cont = -1;
	while (++x_cont < ller->size_x)
	{
		y_cont = -1;
		while (++y_cont < ller->size_y)
		{
//			ft_printf("OK");
			if (field[x_cont][y_cont] == (ller->pl ? 'O' : 'X'))// || ller->pl ? 'o' : 'x'))
				ft_test_distance(ller, x_cont, y_cont, dist);
		}
	}
}

void	ft_filler(char **shape, char **field, t_fi *ller)
{
	int	dist;

//		sleep(999);
	dist = 99999999;
	ller->x = -1;
	while (++ller->x < ller->size_x)
	{
		ller->y = -1;
		while(++ller->y < ller->size_y)
			if (check_insert_shape(shape, field, ller))
				ft_my_xy_to_cont_xy(ller, field, &dist);
//		ft_printf("|%d %d|\n", ller->x, ller->y);
	}
}
