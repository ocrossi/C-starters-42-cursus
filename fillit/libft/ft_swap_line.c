/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_swap_line.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 11:27:53 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 19:08:00 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_swap_line(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strdup(s1);
	ft_strcpy(s1, s2);
	ft_strcpy(s2, tmp);
	ft_strdel(&tmp);
}
