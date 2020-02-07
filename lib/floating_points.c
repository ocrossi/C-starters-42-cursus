/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 18:59:47 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/05 13:27:02 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		rounding_zeropreci(long double *f)
{
	long long		r;
	int				neg;

	neg = (*f < 0) ? TRUE : FALSE;
	*f = (neg == TRUE) ? *f *= -1 : *f;
	r = (long long)(*f);
	*f = *f - r;
	if (*f > 0.5)
		r += 1;
	if (*f == 0.5 || *f == -0.5)
	{
		if (r % 2)
		{
			r += 1;
		}
	}
	*f = *f + r;
	*f = (neg == TRUE) ? *f *= -1 : *f;
}

void		rounding_errors(long double *f, size_t precision)
{
	size_t			partie_entiere;
	long double		fcp;
	size_t			precision_cp;
	long double		rounding;

	if (precision == 0)
		rounding_zeropreci(f);
	fcp = *f;
	fcp = (fcp < 0) ? fcp *= -1 : fcp;
	precision_cp = precision;
	partie_entiere = (size_t)fcp;
	while (precision)
	{
		fcp = fcp * 10;
		partie_entiere = (size_t)fcp;
		fcp = fcp - partie_entiere;
		precision--;
	}
	if (fcp > 0.5 && precision != 0)
	{
		rounding = 0.1;
		while (precision_cp--)
			rounding = rounding / 10;
		*f = *f + rounding;
	}
}

char		*norm_float(long double *f, long long partie_entiere,
		long double save, char *r2)
{
	int i;

	i = ft_strlen(r2);
	*f = *f * 10;
	partie_entiere = (long long)*f;
	save = (long double)partie_entiere;
	*f = *f - save;
	partie_entiere = (*f > 0.5) ? (partie_entiere + 1) : partie_entiere;
	if (partie_entiere == 10)
	{
		partie_entiere = 0;
		r2[i - 1]++;
	}
	r2[i] = partie_entiere + 48;
	return (r2);
}

char		*ft_pf2(long double f, size_t precision, char *r2,
		long long partie_entiere)
{
	long double		save;
	int				i;

	save = 0;
	i = 0;
	r2 = ft_strnew(precision);
	while (precision)
	{
		if (precision == 1)
		{
			r2 = norm_float(&f, partie_entiere, save, r2);
			break ;
		}
		f = f * 10;
		partie_entiere = (long long)f;
		save = (long double)partie_entiere;
		f = f - save;
		r2[i] = partie_entiere + 48;
		precision--;
		i++;
	}
	return (r2);
}

char		*ft_printfloat(long double f, size_t precision, char *r1)
{
	long long		partie_entiere;
	char			*r2;
	char			*r3;

	rounding_errors(&f, precision);
	partie_entiere = (unsigned long long)f;
	r1 = ft_litoa(partie_entiere);
	if (r1[0] == '-')
	{
		f *= -1;
		partie_entiere *= -1;
	}
	if (precision != 0)
	{
		r2 = ft_strjoin(r1, ".");
		ft_strdel(&r1);
		r1 = ft_strdup(r2);
		ft_strdel(&r2);
	}
	else
		return (r1);
	f = f - partie_entiere;
	r2 = ft_pf2(f, precision, r2, partie_entiere);
	end_pf(&r1, &r2, &r3);
	return (r3);
}
