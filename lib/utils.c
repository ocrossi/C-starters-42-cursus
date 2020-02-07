/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 14:30:27 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 17:18:30 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_getsize(char **format)
{
	char	*r;
	char	*tmp;
	int		i;

	tmp = *format;
	i = 0;
	if (!(**format >= '0' && **format <= '9'))
		return (0);
	while (**format >= '0' && **format <= '9')
	{
		*format += 1;
		i++;
	}
	r = ft_strsub(tmp, 0, i);
	i = ft_atoi(r);
	ft_strdel(&r);
	return (i);
}

void	goto_type(char **format)
{
	while (**format)
	{
		if (**format == 's' || **format == 'c' || **format == 'd' ||
				**format == 'u' || **format == 'i' || **format == 'o' ||
				**format == 'x' || **format == 'b' || **format == 'p' ||
				**format == 'f' || **format == 'X' || **format == '%')
			break ;
		*format += 1;
	}
}

int		ft_check_type(char c)
{
	if (c == 's' || c == 'c' || c == 'd' || c == 'i' || c == 'u' || c == 'o' ||
			c == 'x' || c == 'X' || c == 'b' || c == 'p' || c == 'f' ||
			c == '%')
		return (1);
	return (0);
}
