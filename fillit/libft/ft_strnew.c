/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 16:19:47 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:51:50 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char		*res;

	res = (char*)malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	ft_bzero(res, size + 1);
	return (res);
}
