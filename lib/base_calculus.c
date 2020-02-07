/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   base_calculus.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 16:53:43 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 17:06:10 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int				basenum_size(int base, unsigned long long nb)
{
	int			cpt;

	cpt = 0;
	while (nb)
	{
		nb = nb / base;
		cpt++;
	}
	return (cpt);
}

static char				*base_transformation(unsigned long long nb, int base)
{
	int			size;
	char		*ret;

	if (base < 2 || base > 10)
		return (NULL);
	size = basenum_size(base, nb);
	if (!(ret = ft_strnew(size)))
		return (NULL);
	while (size)
	{
		ret[size - 1] = nb % base + 48;
		nb = nb / base;
		size--;
	}
	return (ret);
}

static char				get_hexa(unsigned long long nb)
{
	if (nb == 10)
		return ('a');
	if (nb == 11)
		return ('b');
	if (nb == 12)
		return ('c');
	if (nb == 13)
		return ('d');
	if (nb == 14)
		return ('e');
	if (nb == 15)
		return ('f');
	return (0);
}

static char				*base_hexa(unsigned long long nb)
{
	int			size;
	char		*ret;
	char		*hexa;
	long long	test;

	hexa = "0x";
	size = basenum_size(16, nb);
	if (!(ret = ft_strnew(size)))
		return (NULL);
	while (size)
	{
		test = nb % 16;
		if (test > 9 && test < 16)
			ret[size - 1] = get_hexa(test);
		else
			ret[size - 1] = nb % 16 + 48;
		nb = nb / 16;
		size--;
	}
	return (ret);
}

char					*base_managment(unsigned long long nb, int base)
{
	char		*ret;
	char		*s;

	s = "0";
	if (nb == 0)
		return (ft_strdup(s));
	if (base != 16 && (base >= 2 && base <= 10))
	{
		ret = base_transformation(nb, base);
		return (ret);
	}
	else if (base == 16)
	{
		ret = base_hexa(nb);
		return (ret);
	}
	return (NULL);
}
