/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 10:05:19 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 14:03:35 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char				*s1;
	const char			*s2;
	size_t				i;

	s1 = (char*)dest;
	s2 = (const char *)src;
	i = 0;
	while (i < n)
	{
		if (s2[i] == (char)c)
		{
			s1[i] = s2[i];
			return (&dest[i + 1]);
		}
		s1[i] = s2[i];
		i++;
	}
	return (NULL);
}
