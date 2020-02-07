/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_height_and_width.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 09:28:59 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 20:57:37 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void			find_height_and_width(t_plist *lst)
{
	while (lst != NULL)
	{
		find_width(lst);
		find_height(lst);
		lst = lst->next;
	}
}
