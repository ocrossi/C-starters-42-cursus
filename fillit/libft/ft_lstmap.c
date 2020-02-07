/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 12:37:09 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 14:02:37 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*ret;

	if (lst)
	{
		ret = ft_lstnew(f(lst), ft_strlen(lst->content));
		ret = f(lst);
		ret->next = ft_lstmap(lst->next, f);
	}
	else
	{
		ret = ft_lstnew(NULL, 0);
		return (NULL);
	}
	return (ret);
}
