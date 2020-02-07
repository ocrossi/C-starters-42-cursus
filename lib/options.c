/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   options.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/23 01:41:56 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 17:07:19 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hash(t_func *tab)
{
	char *s;
	char *tmp;

	s = ((*tab).cpt == 5) ? ft_strdup("0") : ft_strdup("0x");
	if ((*tab).width == TRUE && (*tab).zero == TRUE)
	{
		(*tab).width_size -= 2;
		ft_width(tab);
		(*tab).width = FALSE;
	}
	tmp = ft_strjoin(s, (*tab).output);
	ft_strdel(&((*tab).output));
	ft_strdel(&s);
	(*tab).output = ft_strdup(tmp);
	ft_strdel(&tmp);
	(*tab).lenght = ft_strlen((*tab).output);
}

void	ft_plus(t_func *tab)
{
	char *s;
	char *tmp;

	s = "+";
	tmp = ft_strjoin(s, (*tab).output);
	ft_strdel(&((*tab).output));
	(*tab).output = ft_strdup(tmp);
	(*tab).lenght = ft_strlen((*tab).output);
	ft_strdel(&tmp);
}

void	ft_space(t_func *tab)
{
	char *s;
	char *tmp;

	s = " ";
	tmp = ft_strjoin(s, (*tab).output);
	ft_strdel(&((*tab).output));
	(*tab).output = ft_strdup(tmp);
	(*tab).lenght = ft_strlen((*tab).output);
	ft_strdel(&tmp);
}

void	ft_precision_for_str(t_func *tab, int rab)
{
	char *tmp;

	if (rab >= 0)
		return ;
	rab *= -1;
	tmp = ft_strsub((*tab).output, 0, ((*tab).lenght - rab));
	ft_strdel(&((*tab).output));
	(*tab).output = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	ft_precision(t_func *tab)
{
	int		rab;
	int		i;

	i = 0;
	rab = (*tab).precision_size - (*tab).lenght;
	if ((*tab).cpt == 0)
	{
		ft_precision_for_str(tab, rab);
		(*tab).lenght = ft_strlen((*tab).output);
		return ;
	}
	if (rab < 0)
	{
		if ((*tab).type.u == 0 && ((*tab).cpt == 0 || ((*tab).cpt >= 2 &&
						(*tab).cpt <= 7)))
		{
			ft_strdel(&((*tab).output));
			(*tab).output = ft_strnew(1);
		}
		return ;
	}
	ft_precision2(tab, rab, i);
}
