/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_functions_utils.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/15 17:36:12 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 17:39:13 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	negative_ints1(t_func *tab, unsigned long long *nb)
{
	if ((*tab).precision == TRUE)
		(*tab).precision_size += 1;
	(*tab).negative = TRUE;
	*nb = (*tab).type.i * (-1);
	(*tab).output = ft_litoa(*nb);
}

void	negative_ints2(t_func *tab, char *tmp)
{
	tmp = ft_strjoin("-", (*tab).output);
	ft_strdel(&((*tab).output));
	(*tab).output = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	negative_floats(t_func *tab, char *tmp)
{
	tmp = ft_strjoin("-", (*tab).output);
	ft_strdel(&((*tab).output));
	(*tab).output = ft_strdup(tmp);
	ft_strdel(&tmp);
}
