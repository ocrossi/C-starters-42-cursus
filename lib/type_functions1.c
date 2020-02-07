/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_functions1.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/25 19:43:03 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/16 12:54:01 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string(va_list ap, t_func *tab)
{
	int	a;

	a = FALSE;
	(*tab).type.str = va_arg(ap, char *);
	if ((*tab).type.str == NULL)
	{
		a = TRUE;
		(*tab).type.str = ft_strdup("(null)");
	}
	(*tab).lenght = ft_strlen((*tab).type.str);
	(*tab).output = ft_strdup((*tab).type.str);
	check_option_compatibility(tab);
	ft_launch_options(tab);
	(*tab).lenght = ft_strlen((*tab).output);
	if (a == TRUE)
		ft_strdel(&((*tab).type.str));
}

void	ft_print_char(va_list ap, t_func *tab)
{
	int i;

	i = 0;
	(*tab).type.c = va_arg(ap, int);
	(*tab).lenght = 1;
	(*tab).output = ft_strnew(1);
	(*tab).output[0] = (*tab).type.c;
	check_option_compatibility(tab);
	ft_launch_options(tab);
	if ((*tab).type.c == 0)
		i = 1;
	(*tab).lenght = ft_strlen((*tab).output) + i;
	if ((*tab).minus == FALSE)
	{
		ft_putstr((*tab).output);
		if ((*tab).type.c == 0)
			write(1, &((*tab).type.c), 1);
	}
	else
	{
		if ((*tab).type.c == 0)
			write(1, &((*tab).type.c), 1);
		ft_putstr((*tab).output);
	}
}

void	ft_print_unsigned_int(va_list ap, t_func *tab)
{
	if ((*tab).f_l == TRUE)
		(*tab).type.u = va_arg(ap, unsigned long);
	else if ((*tab).f_ll == TRUE)
		(*tab).type.u = va_arg(ap, unsigned long long);
	else
		(*tab).type.u = va_arg(ap, unsigned int);
	if ((*tab).f_hh == TRUE)
		(*tab).type.u = (unsigned char)(*tab).type.u;
	if ((*tab).f_h == TRUE)
		(*tab).type.u = (unsigned short)(*tab).type.u;
	(*tab).output = ft_litoa((*tab).type.u);
	(*tab).lenght = ft_strlen((*tab).output);
	check_option_compatibility(tab);
	ft_launch_options(tab);
	(*tab).lenght = ft_strlen((*tab).output);
}

void	ft_print_int(va_list ap, t_func *tab)
{
	unsigned long long	nb;
	char				*tmp;

	tmp = NULL;
	if ((*tab).f_l == TRUE)
		(*tab).type.i = va_arg(ap, long);
	else if ((*tab).f_ll == TRUE)
		(*tab).type.i = va_arg(ap, long long);
	else
		(*tab).type.i = va_arg(ap, int);
	if ((*tab).f_hh == TRUE)
		(*tab).type.i = (char)(*tab).type.i;
	if ((*tab).f_h == TRUE)
		(*tab).type.i = (short)(*tab).type.i;
	if ((*tab).type.i < 0)
		negative_ints1(tab, &nb);
	else
		(*tab).output = ft_litoa((*tab).type.i);
	if ((*tab).negative == TRUE)
		negative_ints2(tab, tmp);
	(*tab).lenght = ft_strlen((*tab).output);
	check_option_compatibility(tab);
	ft_launch_options(tab);
	(*tab).lenght = ft_strlen((*tab).output);
}

void	ft_print_octal(va_list ap, t_func *tab)
{
	if ((*tab).f_l == TRUE)
		(*tab).type.u = va_arg(ap, unsigned long);
	else if ((*tab).f_ll == TRUE)
		(*tab).type.u = va_arg(ap, unsigned long long);
	else
		(*tab).type.u = va_arg(ap, unsigned long long);
	if ((*tab).f_hh == TRUE)
		(*tab).type.u = (unsigned char)(*tab).type.u;
	if ((*tab).f_h == TRUE)
		(*tab).type.u = (unsigned short)(*tab).type.u;
	(*tab).output = base_managment((*tab).type.i, 8);
	if ((*tab).output == NULL)
		exit(EXIT_FAILURE);
	(*tab).lenght = ft_strlen((*tab).output);
	check_option_compatibility(tab);
	ft_launch_options(tab);
	if ((*tab).type.u == 0 && (*tab).hash == TRUE)
	{
		ft_strdel(&((*tab).output));
		(*tab).output = ft_strdup("0");
	}
	(*tab).lenght = ft_strlen((*tab).output);
}
