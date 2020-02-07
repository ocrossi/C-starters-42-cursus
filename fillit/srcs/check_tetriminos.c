/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_tetriminos.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 13:49:26 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 13:19:57 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		check_tetriminos_size(t_plist **begin)
{
	int		i;
	int		j;
	t_plist	*tmp;

	tmp = *begin;
	while (tmp)
	{
		i = 0;
		j = 0;
		while (tmp->tab[0][j])
		{
			if (tmp->tab[0][j] == '#')
				i++;
			j++;
		}
		if (i != 4)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}

static int		check_numsides_tetriminos(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if ((i % 5 != 0) && str[i - 1] == '#')
				j++;
			if (i > 4 && str[i - 5] == '#')
				j++;
			if (i < 15 && str[i + 5] == '#')
				j++;
			if (((i + 2) % 5 != 0 && str[i + 1] == '#'))
				j++;
		}
		if (j == 6 || j == 8)
			return (1);
		i++;
	}
	return (-1);
}

static int		check_valid_tetriminos(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (!(((i % 5 != 0) && str[i - 1] == '#') || (i > 4 && str[i - 5]
							== '#') || (i < 15 && str[i + 5] == '#') ||
						(((i + 2) % 5 != 0 && str[i + 1] == '#'))))
				return (-1);
		}
		i++;
	}
	if (check_numsides_tetriminos(str) == -1)
		return (-1);
	return (1);
}

int				check_list_tetriminos(t_plist **begin)
{
	t_plist *tmp;

	tmp = *begin;
	if (check_tetriminos_size(begin) == -1)
		return (-1);
	while (tmp)
	{
		if (check_valid_tetriminos((tmp->tab[0])) == -1)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}
