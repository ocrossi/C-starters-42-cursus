/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_width.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 10:24:27 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 09:33:54 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int			check_shitty_shape_width(char **tab, int line, int col)
{
	if (line == 3)
		return (0);
	if (col == 0 || col == 1)
	{
		if (ft_isalpha(tab[line][col + 1]) == 1 &&
		ft_isalpha(tab[line + 1][col + 1]) == 1 &&
		ft_isalpha(tab[line + 1][col + 2]) == 1)
			return (1);
	}
	if (col == 1 || col == 2)
	{
		if (ft_isalpha(tab[line][col + 1]) == 1 &&
		ft_isalpha(tab[line + 1][col]) == 1 &&
		ft_isalpha(tab[line + 1][col - 1]) == 1)
			return (1);
	}
	return (0);
}

static int			find_norm(t_plist *lst, int *line, int *col, int *tmp)
{
	while (ft_isalpha(lst->tab[*line][*col]) == 0 &&
			lst->tab[*line][*col] != '\0')
		(*col)++;
	if (*col == 4)
		return (0);
	if (check_shitty_shape_width(lst->tab, *line, *col) == 1)
	{
		*tmp = 3;
		return (1);
	}
	while (ft_isalpha(lst->tab[*line][*col]) == 1)
	{
		(*col)++;
		lst->width++;
	}
	if (*tmp < lst->width)
		*tmp = lst->width;
	lst->width = 0;
	return (0);
}

void				find_width(t_plist *lst)
{
	int		line;
	int		col;
	int		tmp;

	line = 0;
	col = 0;
	tmp = 0;
	while (lst->tab[line] != NULL)
	{
		while (lst->tab[line][col] != '\0')
		{
			if (find_norm(lst, &line, &col, &tmp) == 1)
				break ;
		}
		col = 0;
		line++;
	}
	if (lst->width < tmp)
		lst->width = tmp;
}
