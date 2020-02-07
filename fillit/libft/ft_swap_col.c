/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_swap_col.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 11:26:05 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 10:22:27 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_swap_col(char **tab, int col, int i, int height)
{
	char	tmp;
	int		line;

	line = 0;
	while (line < height)
	{
		tmp = tab[line][i];
		tab[line][i] = tab[line][col];
		tab[line][col] = tmp;
		line++;
	}
}
