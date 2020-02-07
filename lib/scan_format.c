/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scan_format.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/20 01:19:28 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 17:13:08 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	scan_ll(char **format, t_func *tab)
{
	*format += 1;
	if (**format == 'l')
		(*tab).f_ll = TRUE;
	else
	{
		*format -= 1;
		(*tab).f_l = TRUE;
	}
}

void	scan_hh(char **format, t_func *tab)
{
	*format += 1;
	if (**format == 'h')
		(*tab).f_hh = TRUE;
	else
	{
		*format -= 1;
		(*tab).f_h = TRUE;
	}
}

int		scan_point(char **format, t_func *tab, int r)
{
	(*tab).precision = TRUE;
	*format += 1;
	r = ft_getsize(format);
	(*tab).precision_size = r;
	return (r);
}

int		scan_width(char **format, t_func *tab, int r)
{
	r = ft_getsize(format);
	if (r != 0)
	{
		(*tab).width = TRUE;
		(*tab).width_size = r;
	}
	return (r);
}

void	scan_format(char *format, t_func *tab)
{
	int r;

	scan_options(&format, tab);
	while (*format)
	{
		if (*format == 's' || *format == 'c' || *format == 'd' || *format == 'u'
		|| *format == 'i' || *format == 'o' || *format == 'x' || *format == 'b'
		|| *format == 'p' || *format == 'f' || *format == 'X' || *format == '%')
			break ;
		if (*format >= '0' && *format <= '9')
			r = scan_width(&format, tab, r);
		if (*format == '.')
			r = scan_point(&format, tab, r);
		if (*format == 'h')
			scan_hh(&format, tab);
		if (*format == 'l')
			scan_ll(&format, tab);
		if (*format == 'L')
			(*tab).f_gl = TRUE;
		if (*format != 's' && *format != 'c' && *format != 'd' &&
				*format != 'u' && *format != 'i' && *format != 'o' &&
				*format != 'x' && *format != 'b' && *format != 'p' &&
				*format != 'f' && *format != 'X' && *format != '%')
			format += 1;
	}
}
