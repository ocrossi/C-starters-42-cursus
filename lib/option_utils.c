/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   option_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/15 17:32:32 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/16 12:58:20 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_width2_space(t_func *tab, char *r, char *tmp)
{
	char *tmp1;

	tmp1 = NULL;
	tmp = ft_strdup((*tab).output + 1);
	ft_strdel(&((*tab).output));
	tmp1 = ft_strjoin(r, tmp);
	(*tab).output = ft_strjoin(" ", tmp1);
	ft_strdel(&tmp1);
	ft_strdel(&r);
	ft_strdel(&tmp);
}

void		check_option_compatibility4(t_func *tab)
{
	if ((*tab).precision == TRUE && ((*tab).cpt == 1 || (*tab).cpt == 9))
		(*tab).precision = FALSE;
	if (((*tab).cpt == 0 || (*tab).cpt == 1 || (*tab).cpt == 9 || (*tab).cpt ==
				6 || (*tab).cpt == 4 || (*tab).cpt == 7 || (*tab).plus == TRUE)
			&& (*tab).space == TRUE)
		(*tab).space = FALSE;
	if ((*tab).width == TRUE && (*tab).hash == TRUE && (*tab).width_size >= 1 &&
			(*tab).cpt == 5)
		(*tab).width_size--;
	if (((*tab).cpt == 6 || (*tab).cpt == 7) && (*tab).type.u == 0 &&
			(*tab).hash == TRUE)
		(*tab).hash = FALSE;
	if ((*tab).cpt == 11)
	{
		(*tab).precision = FALSE;
		(*tab).plus = FALSE;
	}
}

void		check_option_compatibility3(t_func *tab)
{
	if ((*tab).cpt == 9)
		(*tab).hash = TRUE;
	if (((*tab).cpt >= 5 && (*tab).cpt <= 7) && (*tab).width == TRUE
			&& (*tab).precision == TRUE && (*tab).zero == TRUE)
		(*tab).zero = FALSE;
	if ((*tab).cpt == 5 && (*tab).width == TRUE && (*tab).hash == TRUE &&
			(*tab).precision == FALSE)
		(*tab).width_size += 1;
	if ((*tab).cpt == 5 && (*tab).width == TRUE && (*tab).hash == TRUE &&
			(*tab).precision == TRUE)
		(*tab).hash = FALSE;
	if (((*tab).cpt == 0 || (*tab).cpt == 1 || (*tab).cpt == 9 || (*tab).cpt ==
				5 || (*tab).cpt == 4 || (*tab).cpt == 6 || (*tab).cpt == 7) &&
			(*tab).plus == TRUE)
		(*tab).plus = FALSE;
	if ((*tab).zero == TRUE && (*tab).minus == TRUE)
		(*tab).zero = FALSE;
	if ((*tab).hash == TRUE && (*tab).cpt == 1)
		(*tab).hash = FALSE;
	check_option_compatibility4(tab);
}
