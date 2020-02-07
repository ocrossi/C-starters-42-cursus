/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprint.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 16:24:42 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 22:13:36 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pr_begin(char **format, t_func *tab)
{
	char *tmp;

	*format += 1;
	tmp = (char*)*format;
	scan_format(tmp, tab);
	tmp = (char*)*format;
	goto_type(&tmp);
	*format = tmp;
	return (tmp);
}

int		percent_managment_for_spf(const char **format, va_list ap, t_func *tab,
		char s[])
{
	char *tmp;

	tmp = pr_begin((char **)format, tab);
	if (ft_check_type(**format))
	{
		while ((*tab).tab_type[(*tab).cpt] && (*tab).tab_type[(*tab).cpt] !=
				**format)
			(*tab).cpt++;
	}
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
		ft_strcat(s, (*tab).output);
	return (1);
}

int		ft_sprintf(char s[], const char *format, ...)
{
	va_list		ap;
	t_func		tab;
	int			i;

	i = 0;
	tab = ft_init_tab_type();
	va_start(ap, format);
	while (*format)
	{
		ft_init_options(&tab);
		while (*format && *format != '%')
		{
			s[i++] = (*format++);
			tab.ret++;
		}
		if (*format)
		{
			percent_managment_for_spf(&format, ap, &tab, s);
			i = i + ft_strlen(tab.output);
		}
		if (tab.output != NULL)
			ft_strdel(&(tab.output));
	}
	return (tab.ret);
}
