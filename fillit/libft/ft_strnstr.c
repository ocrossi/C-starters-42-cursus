/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 13:11:43 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 14:12:40 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (s2[j] == '\0')
		return ((char*)&s1[i]);
	while (i < n)
	{
		while (s1[i + j] == s2[j] && (i + j) < n && s2[j] != '\0')
			j++;
		if (s2[j] == '\0')
			return ((char*)&s1[i]);
		else if (s1[i] == '\0')
			return (NULL);
		else
		{
			j = 0;
			i++;
		}
	}
	return (NULL);
}
