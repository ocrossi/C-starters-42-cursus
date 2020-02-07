/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 22:43:02 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:39:22 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	int			i;
	int			len_s1;

	i = 0;
	len_s1 = ft_strlen(s1);
	if (!s1 && !s2)
		return (NULL);
	res = (char*)malloc(sizeof(char) * (len_s1 + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		res[len_s1 + i] = s2[i];
		i++;
	}
	res[len_s1 + i] = '\0';
	return (res);
}
