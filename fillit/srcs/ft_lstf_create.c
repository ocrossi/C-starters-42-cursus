/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstf_create.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 11:13:43 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 13:49:19 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static t_plist		*lstinit(t_plist *new, int size[2], int coord[2])
{
	new->tab[0] = ft_strdup("\0");
	new->tab[1] = NULL;
	new->tab[2] = NULL;
	new->tab[3] = NULL;
	new->size[0] = size[0];
	new->size[1] = size[1];
	new->height = new->size[0];
	new->width = new->size[1];
	new->coord[0] = coord[0];
	new->coord[1] = coord[1];
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_plist				*ft_lstfnew(char *tab, char c, int size[2], int coord[2])
{
	t_plist		*new;

	if (!(new = (t_plist*)malloc(sizeof(t_plist))))
		return (NULL);
	if (!(new->tab = (char**)malloc((sizeof(char*) * 4))))
	{
		ft_lstfdelone(&new, del_elem, del_elem2);
		return (NULL);
	}
	if (!tab || !c)
	{
		ft_lstfdelone(&new, del_elem, del_elem2);
		return (NULL);
	}
	new->c = c;
	new = lstinit(new, size, coord);
	return (new);
}

void				ft_lstfaddend(t_plist **begin, t_plist *new)
{
	t_plist		*tmp;

	if (!begin || !(*begin) || !new)
		return ;
	tmp = *begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}
