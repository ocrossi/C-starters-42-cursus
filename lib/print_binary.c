/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_binary.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 15:53:57 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 22:13:09 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char		*split_seg(char *r, int idx)
{
	int		i;
	char	*sp;

	i = 0;
	sp = " || ";
	while (i < 4)
		r[idx++] = sp[i++];
	return (r);
}

char		*stock_seg(char *str)
{
	char	*r;
	int		i;
	int		j;
	int		size_ret;
	int		size;

	i = 0;
	j = 0;
	size = ft_strlen(str);
	size_ret = 4 * ((size / 8) - 1);
	if (!(r = ft_strnew(size + size_ret)))
		return (NULL);
	while (str[i])
	{
		if (i % 8 == 0 && i != 0)
		{
			r = split_seg(r, i);
			j += 4;
		}
		r[j] = str[i];
		i++;
		j++;
	}
	return (r);
}

void		store_bytes(char *str, t_func *tab)
{
	int		cpt;
	int		rab;
	int		i;
	char	*seg;

	i = 0;
	rab = 0;
	cpt = ft_strlen(str);
	while (cpt % 8 != 0)
	{
		rab++;
		cpt++;
	}
	if (!(seg = ft_strnew(cpt)))
		exit(EXIT_FAILURE);
	while (rab)
	{
		seg[i] = '0';
		i++;
		rab--;
	}
	seg = ft_strcat(seg, str);
	tab->output = stock_seg(seg);
	ft_strdel(&str);
}
