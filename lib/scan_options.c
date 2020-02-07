/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scan_options.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 13:39:13 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 17:10:41 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_options2(char **format, t_func *tab)
{
	if (**format == ' ')
	{
		(*tab).space = TRUE;
		*format += 1;
		while (*format && **format == ' ')
			*format += 1;
	}
	if (**format == '0' && ((*tab).zero != TRUE))
	{
		*format += 1;
		(*tab).zero = TRUE;
	}
	if (**format == '0')
		*format += 1;
	if (**format == '-')
	{
		*format += 1;
		(*tab).minus = TRUE;
	}
}

void	scan_options(char **format, t_func *tab)
{
	static int tarace;

	tarace = 0;
	tarace++;
	while ((**format == '0' || **format == '-' || **format == '+'
				|| **format == '#' || **format == ' ' || **format == '%'))
	{
		ft_options2(format, tab);
		if (**format == '+')
		{
			*format += 1;
			(*tab).plus = TRUE;
		}
		else if (**format == '#')
		{
			*format += 1;
			(*tab).hash = TRUE;
		}
		else
		{
			if (**format == '\0' || (**format != '0' && **format != '-' &&
						**format != '+' && **format != '#' && **format != ' '))
				break ;
		}
	}
}
