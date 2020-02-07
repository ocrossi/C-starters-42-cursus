/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/07 22:18:36 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 17:25:03 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_options(t_func *tab)
{
	(*tab).output = NULL;
	(*tab).lenght = 0;
	(*tab).cpt = 0;
	(*tab).f_hh = FALSE;
	(*tab).f_h = FALSE;
	(*tab).f_l = FALSE;
	(*tab).f_ll = FALSE;
	(*tab).f_gl = FALSE;
	(*tab).precision = FALSE;
	(*tab).precision_size = 6;
	(*tab).minus = FALSE;
	(*tab).plus = FALSE;
	(*tab).hash = FALSE;
	(*tab).zero = FALSE;
	(*tab).space = FALSE;
	(*tab).width = FALSE;
	(*tab).width_size = 0;
	(*tab).negative = FALSE;
}

void	ft_init_tab_type2(t_func *tab)
{
	(*tab).f[0] = &ft_print_string;
	(*tab).f[1] = &ft_print_char;
	(*tab).f[2] = &ft_print_int;
	(*tab).f[3] = &ft_print_int;
	(*tab).f[4] = &ft_print_unsigned_int;
	(*tab).f[5] = &ft_print_octal;
	(*tab).f[6] = &ft_print_hexa;
	(*tab).f[7] = &ft_print_hexac;
	(*tab).f[8] = &ft_print_binary;
	(*tab).f[9] = &ft_print_hexa;
	(*tab).f[10] = &ft_print_fl;
	(*tab).f[11] = &ft_print_percent;
}

t_func	ft_init_tab_type(void)
{
	t_func	tab;

	tab.ret = 0;
	tab.tab_type[0] = 's';
	tab.tab_type[1] = 'c';
	tab.tab_type[2] = 'd';
	tab.tab_type[3] = 'i';
	tab.tab_type[4] = 'u';
	tab.tab_type[5] = 'o';
	tab.tab_type[6] = 'x';
	tab.tab_type[7] = 'X';
	tab.tab_type[8] = 'b';
	tab.tab_type[9] = 'p';
	tab.tab_type[10] = 'f';
	tab.tab_type[11] = '%';
	ft_init_tab_type2(&tab);
	ft_init_options(&tab);
	return (tab);
}

int		percent_managment(const char **format, va_list ap, t_func *tab)
{
	char *tmp;

	*format += 1;
	tmp = (char*)*format;
	scan_format(tmp, tab);
	tmp = (char*)*format;
	goto_type(&tmp);
	*format = tmp;
	if (ft_check_type(**format))
		while ((*tab).tab_type[(*tab).cpt] && (*tab).tab_type[(*tab).cpt] !=
				**format)
			(*tab).cpt++;
	else
		(*tab).output = ft_strdup("");
	if ((*tab).tab_type[(*tab).cpt] && (*tab).tab_type[(*tab).cpt] == **format)
		(*tab).f[(*tab).cpt](ap, tab);
	else if (**format != '%')
		return (0);
	if (**format && ft_check_type(**format))
		*format += 1;
	(*tab).ret = (*tab).ret + (*tab).lenght;
	if ((*tab).cpt != 1)
		ft_putstr((*tab).output);
	return (1);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_func		tab;

	tab = ft_init_tab_type();
	va_start(ap, format);
	while (*format)
	{
		while (*format && *format != '%')
		{
			write(1, &(*format++), 1);
			tab.ret++;
		}
		if (*format)
			percent_managment(&format, ap, &tab);
		if (tab.output != NULL)
			ft_strdel(&(tab.output));
		ft_init_options(&tab);
	}
	if (tab.output)
	{
		ft_strdel(&(tab.output));
		ft_init_options(&tab);
	}
	va_end(ap);
	return (tab.ret);
}
