/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstf_countnodes.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/28 15:30:38 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 20:31:39 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_lstf_countnodes(t_plist *begin)
{
	int i;

	i = 0;
	while (begin)
	{
		begin = begin->next;
		i++;
	}
	return (i);
}
