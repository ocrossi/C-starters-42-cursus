/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_tetri_up_left.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 10:28:08 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 21:01:40 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static void		move_square(t_plist *lst, int line, int col, int i)
{
	while (i < lst->height)
	{
		ft_swap_line(lst->tab[i], lst->tab[line]);
		i++;
		line++;
	}
	i = 0;
	line = 0;
	while (line < lst->width)
	{
		ft_swap_col(lst->tab, col, i, lst->height);
		i++;
		line++;
		col++;
	}
}

static void		move_3x2(t_plist *lst, int line, int col, int i)
{
	while (i < lst->height)
	{
		ft_swap_line(lst->tab[i], lst->tab[line]);
		i++;
		line++;
	}
	i = 0;
	line = 0;
	if (col != 0)
	{
		if (col != 3)
			col = find_col_3x2(lst, line, col);
		else
			col = 1;
		while (line < lst->width)
		{
			ft_swap_col(lst->tab, col, i, lst->height);
			i++;
			line++;
			col++;
		}
	}
}

static void		move_2x3(t_plist *lst, int line, int col, int i)
{
	while (i < lst->height)
	{
		ft_swap_line(lst->tab[i], lst->tab[line]);
		i++;
		line++;
	}
	i = 0;
	line = 0;
	if (col != 0)
	{
		if (ft_isalpha(lst->tab[line + 1][col - 1]) == 1 ||
				ft_isalpha(lst->tab[line + 2][col - 1]) == 1)
			col--;
		while (line < lst->width)
		{
			ft_swap_col(lst->tab, col, i, lst->height);
			i++;
			line++;
			col++;
		}
	}
}

static void		move_norm(t_plist *lst, int *col, int *line)
{
	while (ft_isalpha(lst->tab[*line][*col]) == 0)
	{
		(*col)++;
		if (lst->tab[*line][*col] == '\0' && *line != 3)
		{
			*col = 0;
			(*line)++;
		}
	}
}

void			move_all_tetri_up_left(t_plist *lst)
{
	int		line;
	int		col;
	int		i;

	i = 0;
	line = 0;
	col = 0;
	while (lst != NULL)
	{
		move_norm(lst, &col, &line);
		if (lst->width == 4)
			ft_swap_line(lst->tab[0], lst->tab[line]);
		else if (lst->height == 4)
			ft_swap_col(lst->tab, col, i, lst->height);
		else if (lst->height == 2 && lst->width == 2)
			move_square(lst, line, col, i);
		else if (lst->height == 2 && lst->width == 3)
			move_3x2(lst, line, col, i);
		else if (lst->height == 3 && lst->width == 2)
			move_2x3(lst, line, col, i);
		line = 0;
		col = 0;
		lst = lst->next;
	}
}
