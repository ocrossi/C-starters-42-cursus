/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   switch_to.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 09:45:16 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 19:06:04 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void			switch_to_char(t_plist *lst)
{
	int			i;

	i = 0;
	while (lst != NULL)
	{
		while (lst->tab[0][i] != '\0')
		{
			while (lst->tab[0][i] == '#')
			{
				lst->tab[0][i] = lst->c;
				i++;
			}
			i++;
		}
		i = 0;
		lst = lst->next;
	}
}

void			switch_to_2d(t_plist **begin)
{
	t_plist		*tmp_l;
	char		*tmp_s;
	int			i;

	i = 0;
	tmp_l = *begin;
	while (tmp_l != NULL)
	{
		tmp_s = ft_strdup(tmp_l->tab[0]);
		ft_strdel(&(tmp_l->tab[0]));
		free(tmp_l->tab);
		tmp_l->tab = NULL;
		tmp_l->tab = ft_strsplit(tmp_s, '\n');
		ft_strdel(&tmp_s);
		tmp_l = tmp_l->next;
	}
}
