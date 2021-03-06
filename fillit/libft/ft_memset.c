/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 09:58:15 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 14:16:11 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *str, int c, size_t n)
{
	size_t		i;
	char		*s;

	i = 0;
	s = (char *)str;
	while (i < n)
	{
		s[i] = (char)c;
		i++;
	}
	return (s);
}
