/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstfdel_list.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 17:16:39 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 17:18:24 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void			del_elem2(int size[2], int coord[2])
{
	size[0] = 0;
	size[1] = 0;
	coord[0] = 0;
	coord[1] = 0;
}

void			del_elem(char c, char **tab, int height, int width)
{
	int i;

	i = 0;
	c = 0;
	while (i < 4)
	{
		i++;
		free(tab[i - 1]);
	}
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	height = 0;
	width = 0;
}

void			ft_lstfdelone(t_plist **current, void (*del_elem)(char c,
			char **tab, int height, int width),
		void (*del_elem2)(int size[2], int coord[2]))
{
	(del_elem)((*current)->c, (*current)->tab, (*current)->height,
			(*current)->width);
	(del_elem2)((*current)->size, (*current)->coord);
	(*current)->prev = NULL;
	*current = NULL;
}
