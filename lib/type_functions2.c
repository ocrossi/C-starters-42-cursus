/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_functions2.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/25 19:46:39 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 21:48:36 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_binary(va_list ap, t_func *tab)
{
	char *r;

	(void)tab;
	(*tab).type.i = va_arg(ap, long long);
	r = base_managment((*tab).type.i, 2);
	if (r == NULL)
		exit(EXIT_FAILURE);
	store_bytes(r, tab);
}

void	ft_print_hexa(va_list ap, t_func *tab)
{
	if ((*tab).f_l == TRUE && (*tab).cpt != 9)
		(*tab).type.u = va_arg(ap, unsigned long);
	else if ((*tab).f_ll == TRUE || (*tab).cpt == 9)
		(*tab).type.u = va_arg(ap, unsigned long long);
	else
		(*tab).type.u = va_arg(ap, unsigned int);
	if ((*tab).f_hh == TRUE)
		(*tab).type.u = (unsigned char)(*tab).type.u;
	if ((*tab).f_h == TRUE)
		(*tab).type.u = (unsigned short)(*tab).type.u;
	(*tab).output = base_managment((*tab).type.u, 16);
	if ((*tab).cpt == 9)
		(*tab).hash = TRUE;
	if ((*tab).output == NULL)
		exit(EXIT_FAILURE);
	(*tab).lenght = ft_strlen((*tab).output);
	check_option_compatibility(tab);
	ft_launch_options(tab);
	(*tab).lenght = ft_strlen((*tab).output);
}

void	ft_print_hexac(va_list ap, t_func *tab)
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
	(*tab).output = base_managment((*tab).type.u, 16);
	if ((*tab).output == NULL)
		exit(EXIT_FAILURE);
	(*tab).lenght = ft_strlen((*tab).output);
	check_option_compatibility(tab);
	ft_launch_options(tab);
	(*tab).lenght = ft_strlen((*tab).output);
	(*tab).output = ft_strcapitalize((*tab).output);
}

void	ft_print_fl(va_list ap, t_func *tab)
{
	char *r;
	char *tmp;

	r = NULL;
	tmp = NULL;
	if ((*tab).f_gl == TRUE)
		(*tab).type.f = va_arg(ap, long double);
	else
		(*tab).type.f = va_arg(ap, double);
	if ((*tab).type.f < 0)
	{
		(*tab).negative = TRUE;
		(*tab).type.f *= (-1);
	}
	(*tab).output = ft_printfloat(((*tab).type.f),
			(*tab).precision_size, r);
	if ((*tab).negative == TRUE)
		negative_floats(tab, tmp);
	(*tab).lenght = ft_strlen((*tab).output);
	(*tab).precision = FALSE;
	check_option_compatibility(tab);
	ft_launch_options(tab);
	(*tab).lenght = ft_strlen((*tab).output);
}

void	ft_print_percent(va_list ap, t_func *tab)
{
	(void)ap;
	(*tab).lenght = 1;
	(*tab).output = ft_strdup("%");
	check_option_compatibility(tab);
	ft_launch_options(tab);
	(*tab).lenght = ft_strlen((*tab).output);
}
