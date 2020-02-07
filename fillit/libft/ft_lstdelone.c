/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdelone.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 19:11:39 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 14:02:11 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list			*lst;

	if (!*alst || !alst || !del)
		return ;
	lst = *alst;
	(*del)(lst->content, lst->content_size);
	ft_memdel((void**)alst);
}
