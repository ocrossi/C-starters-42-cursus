/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vive_la_norme.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 11:18:38 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 10:43:26 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int			find_col_3x2(t_plist *lst, int line, int col)
{
	if (ft_isalpha(lst->tab[line][col + 1]) == 0 &&
		ft_isalpha(lst->tab[line][col - 1]) == 0 &&
		ft_isalpha(lst->tab[line + 1][col - 1]) == 1)
		col--;
	if (col != 0)
	{
		if (ft_isalpha(lst->tab[line + 1][col - 1]) == 1 &&
		(ft_isalpha(lst->tab[line + 1][col + 1]) == 1 ||
		ft_isalpha(lst->tab[line + 1][col + 1]) == 0))
			col--;
	}
	return (col);
}
