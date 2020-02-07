/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_and_remove.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 21:27:13 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 14:21:12 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	print_tetriminos(int line, int col, t_sqs *s_map, t_plist *current)
{
	int i;
	int col_ref;
	int j;

	i = 0;
	j = 0;
	col_ref = col;
	while (i < current->height)
	{
		while (j < current->width)
		{
			if (current->tab[i][j] == current->c)
				(*s_map).map[line][col] = current->c;
			col++;
			j++;
		}
		j = 0;
		i++;
		line++;
		col = col_ref;
	}
}

void	remove_tetriminos(int line, int col, t_sqs *s_map, t_plist *current)
{
	int		i;
	int		j;
	int		col_ref;

	i = 0;
	j = 0;
	col_ref = col;
	while (i < current->height)
	{
		while (j < current->width)
		{
			if (current->tab[i][j] == current->c)
				(*s_map).map[line][col] = '.';
			col++;
			j++;
		}
		j = 0;
		i++;
		line++;
		col = col_ref;
	}
}
