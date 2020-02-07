/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_height.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 09:52:41 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 11:22:22 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int			check_shitty_shape_height(char **tab, int line, int col)
{
	if (line == 2 || line == 3)
		return (-1);
	if (col != 3)
	{
		if (ft_isalpha(tab[line + 1][col]) == 1 &&
			ft_isalpha(tab[line + 1][col + 1]) == 1 &&
			ft_isalpha(tab[line + 2][col + 1]) == 1)
			return (1);
	}
	if (col != 0)
	{
		if (ft_isalpha(tab[line + 1][col]) == 1 &&
			ft_isalpha(tab[line + 1][col - 1]) == 1 &&
			ft_isalpha(tab[line + 2][col - 1]) == 1)
			return (1);
	}
	return (0);
}

static int			find_first_el(t_plist *lst, int line, int col)
{
	while (ft_isalpha(lst->tab[line][col]) == 0 &&
			lst->tab[line][col] != '\0')
		col++;
	if (lst->tab[line + 1] != NULL && lst->width != 4)
	{
		while (ft_isalpha(lst->tab[line + 1][col]) == 0 &&
				lst->tab[line + 1][col] != '\0')
			col++;
	}
	return (col);
}

void				find_height(t_plist *lst)
{
	int		line;
	int		col;

	line = 0;
	col = 0;
	while (lst->tab[line] != NULL)
	{
		col = find_first_el(lst, line, col);
		while (ft_isalpha(lst->tab[line][col]) == 1)
		{
			if (check_shitty_shape_height(lst->tab, line, col) == 1)
			{
				lst->height = 3;
				return ;
			}
			lst->height++;
			if (lst->tab[line + 1] == NULL)
				break ;
			line++;
		}
		line++;
		col = 0;
	}
}
