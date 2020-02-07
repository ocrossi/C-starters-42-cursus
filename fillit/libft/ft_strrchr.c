/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 12:41:13 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 14:12:48 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		s_len;

	s_len = ft_strlen(s);
	while (s[s_len] != c)
	{
		s_len--;
		if (s_len == -1)
			return (NULL);
	}
	return ((char*)&s[s_len]);
}
