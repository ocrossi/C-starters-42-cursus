/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recursive_factorial.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 13:39:30 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 14:07:59 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_recursive_factorial(int nb)
{
	if (nb <= -1 || nb >= 13)
		return (0);
	if (nb == 0)
		return (1);
	if (nb != 1)
		nb = nb * ft_recursive_factorial(nb - 1);
	return (nb);
}
