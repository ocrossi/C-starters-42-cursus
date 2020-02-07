/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   option_managment.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/21 20:27:31 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 17:34:26 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_zero(char **str)
{
	int		l;
	int		i;
	char	*r;

	i = 0;
	l = ft_strlen(*str);
	r = ft_strnew(l);
	while (l)
	{
		r[i] = '0';
		l--;
		i++;
	}
	ft_strdel(str);
	return (r);
}

void	ft_width(t_func *tab)
{
	char	*r;
	int		i;
	int		cpt;

	i = 0;
	if ((*tab).width_size <= (*tab).lenght)
		return ;
	(*tab).width_size = (*tab).width_size - (*tab).lenght;
	r = ft_strnew((*tab).width_size);
	cpt = (*tab).width_size;
	while (cpt)
	{
		r[i] = ' ';
		i++;
		cpt--;
	}
	ft_width2(tab, r);
}

void	check_option_compatibility2(t_func *tab)
{
	if ((*tab).cpt == 9 && (*tab).precision == TRUE)
		(*tab).precision = FALSE;
	if ((*tab).cpt == 8)
	{
		(*tab).minus = FALSE;
		(*tab).plus = FALSE;
		(*tab).space = FALSE;
		(*tab).width = FALSE;
		(*tab).zero = FALSE;
		(*tab).precision = FALSE;
		(*tab).hash = FALSE;
	}
	if ((*tab).cpt == 11 && (*tab).space == TRUE)
		(*tab).space = FALSE;
	if ((*tab).negative == TRUE)
		(*tab).plus = FALSE;
	if (((*tab).cpt == 1 || (*tab).cpt == 2) && ((*tab).type.i == 0 &&
				(*tab).hash == TRUE && ((*tab).cpt != 5)))
		(*tab).hash = FALSE;
	if ((*tab).negative == TRUE && ((*tab).cpt == 2 || (*tab).cpt == 3)
			&& (*tab).space == TRUE)
		(*tab).space = FALSE;
	if ((*tab).plus == TRUE && (*tab).width_size >= 1 && (*tab).zero == TRUE)
		(*tab).width_size -= 1;
	check_option_compatibility3(tab);
}

void	check_option_compatibility(t_func *tab)
{
	if ((*tab).cpt == 1 && (*tab).space == TRUE)
		(*tab).space = FALSE;
	if ((*tab).plus == TRUE && (*tab).space == TRUE)
		(*tab).space = FALSE;
	if ((*tab).minus == TRUE && (*tab).zero == TRUE)
		(*tab).zero = FALSE;
	if ((*tab).minus == TRUE && (*tab).zero == TRUE)
		(*tab).zero = FALSE;
	if ((*tab).precision == TRUE && (*tab).cpt == 9)
		(*tab).precision = FALSE;
	if ((*tab).cpt == 9 && (*tab).hash == TRUE)
		(*tab).hash = FALSE;
	if ((*tab).precision == TRUE && (*tab).zero == TRUE &&
			((*tab).cpt >= 2 && (*tab).cpt <= 4))
		(*tab).zero = FALSE;
	if (((*tab).cpt == 0 || (*tab).cpt == 1 || (*tab).cpt == 2 ||
				(*tab).cpt == 3 || (*tab).cpt == 4 || (*tab).cpt == 10 ||
				(*tab).cpt == 8 || (*tab).cpt == 11)
			&& (*tab).hash == TRUE)
		(*tab).hash = FALSE;
	check_option_compatibility2(tab);
}

void	ft_launch_options(t_func *tab)
{
	if ((*tab).precision == TRUE && ((*tab).negative == FALSE &&
				(*tab).plus == FALSE))
	{
		ft_precision(tab);
		(*tab).lenght = ft_strlen((*tab).output);
	}
	if ((*tab).plus == TRUE && (*tab).zero == FALSE &&
			(*tab).precision == FALSE)
		ft_plus(tab);
	if ((*tab).hash == TRUE)
		ft_hash(tab);
	if ((*tab).space == TRUE)
		ft_space(tab);
	if (((*tab).precision == TRUE || (*tab).zero == TRUE) &&
			((*tab).negative == TRUE || (*tab).plus == TRUE))
		ft_width_complicated(tab);
	if ((*tab).width == TRUE)
		ft_width(tab);
}
