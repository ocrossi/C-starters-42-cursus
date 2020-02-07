/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   options2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/24 04:16:56 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/16 12:56:16 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_width_complicated(t_func *tab)
{
	char *sign;
	char *tmp;

	sign = ((*tab).plus == TRUE) ? "+" : "-";
	if ((*tab).width_size >= 1 && (*tab).zero == FALSE)
		(*tab).width_size -= 1;
	if ((*tab).negative == TRUE)
	{
		tmp = ft_strsub((*tab).output, 1, (ft_strlen((*tab).output) - 1));
		ft_strdel(&((*tab).output));
		(*tab).output = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	if ((*tab).precision == TRUE)
		ft_precision(tab);
	if ((*tab).width == TRUE && (*tab).zero == TRUE)
	{
		ft_width(tab);
		(*tab).width = FALSE;
	}
	tmp = ft_strjoin(sign, (*tab).output);
	ft_strdel(&((*tab).output));
	(*tab).output = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void		scan_bout_de_scotch(char **r3)
{
	int		cpt;
	char	*tmp;

	cpt = ft_strlen(*r3);
	tmp = *r3;
	*r3 += cpt;
	while (cpt)
	{
		if (**r3 == ':')
		{
			**r3 = '0';
			*r3 -= 1;
			scan_bout_de_scotch2(r3, &cpt);
		}
		cpt--;
		*r3 -= 1;
	}
	*r3 = tmp;
}

void		end_pf(char **r1, char **r2, char **r3)
{
	*r3 = ft_strjoin(*r1, *r2);
	scan_bout_de_scotch(r3);
	ft_strdel(r1);
	ft_strdel(r2);
}

void		ft_width2(t_func *tab, char *r)
{
	char *tmp;

	if ((*tab).minus == TRUE)
		tmp = ft_strjoin((*tab).output, r);
	else
	{
		if ((*tab).zero == TRUE)
		{
			tmp = ft_zero(&r);
			ft_strdel(&r);
			r = ft_strdup(tmp);
			ft_strdel(&tmp);
		}
		if ((*tab).space == TRUE)
		{
			ft_width2_space(tab, r, tmp);
			return ;
		}
		else
			tmp = ft_strjoin(r, (*tab).output);
	}
	ft_strdel(&r);
	ft_strdel(&(*tab).output);
	(*tab).output = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void		ft_precision2(t_func *tab, int rab, int i)
{
	char *str;
	char *r;

	rab++;
	if (!(str = (char*)malloc(sizeof(char) * rab)))
		return ;
	str[rab - 1] = '\0';
	while (i < rab - 1)
	{
		str[i] = '0';
		i++;
	}
	r = ft_strjoin(str, (*tab).output);
	ft_strdel(&(*tab).output);
	(*tab).output = ft_strdup(r);
	(*tab).lenght = ft_strlen((*tab).output);
	ft_strdel(&r);
	ft_strdel(&str);
}
