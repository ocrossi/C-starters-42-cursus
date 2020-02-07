/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstfdel_list2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 15:03:09 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 13:42:49 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static void		deref(t_plist *current)
{
	current->c = 0;
	current->height = 0;
	current->width = 0;
	current->size[0] = 0;
	current->size[1] = 0;
	current->coord[0] = 0;
	current->coord[1] = 0;
	current->next = NULL;
	current->c = 0;
}

static void		del_toide(t_plist **current, int i)
{
	while (i < 4)
	{
		free((*current)->tab[i]);
		(*current)->tab[i] = NULL;
		i++;
	}
	deref(*current);
	free((*current)->tab);
	(*current)->tab = NULL;
	free(*current);
	*current = NULL;
}

static void		del_taplane(t_plist **current)
{
	t_plist *tmp;
	int		i;

	i = 0;
	if ((*current)->prev == NULL)
	{
		del_toide(current, i);
		return ;
	}
	else
	{
		while (i < 4)
		{
			free((*current)->tab[i]);
			(*current)->tab[i] = NULL;
			i++;
		}
		free((*current)->tab);
		(*current)->tab = NULL;
		tmp = *current;
		deref(tmp);
		*current = (*current)->prev;
		free(tmp);
		tmp = NULL;
	}
}

void			ft_lstfdel_list2(t_plist *begin)
{
	t_plist *tmp;

	tmp = begin;
	while (begin->next)
		begin = begin->next;
	while (begin != tmp)
		del_taplane(&begin);
	del_taplane(&begin);
}
