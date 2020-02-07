/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_map.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 11:23:13 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 11:24:17 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		check_size_and_char_one_tetri(t_plist *lst)
{
	int				j;
	int				size;

	j = 0;
	size = 0;
	while (lst->tab[0][j] == '.' || lst->tab[0][j] == '#' ||
			lst->tab[0][j] == '\n')
	{
		j++;
		size++;
	}
	if (size == 20)
		return (1);
	return (0);
}

static int		check_size_and_char(t_plist *lst, int nb_tetri)
{
	int				j;
	int				size;
	static int		ret;

	j = 0;
	size = 0;
	while (lst->tab[0][j] != '\0')
	{
		if (lst->tab[0][j] == '.' || lst->tab[0][j] == '#' ||
			lst->tab[0][4] == '\n' || lst->tab[0][9] == '\n' || lst->tab[0][14]
			== '\n' || lst->tab[0][19] == '\n' || lst->tab[0][20] == '\n')
		{
			size++;
			j++;
		}
		else
			j++;
	}
	if (size == 21)
		ret++;
	else if (lst->next == NULL && size == 20)
		ret++;
	if (ret == nb_tetri)
		return (1);
	return (0);
}

static int		check_feed_nb_one_tetri(t_plist *lst)
{
	int			j;
	int			tmp;
	int			feed_nb;

	j = 0;
	tmp = 0;
	feed_nb = 0;
	while (lst->tab[0][j])
	{
		if (lst->tab[0][j] == '\n' && lst->tab[0][j + 1] == '\n')
			break ;
		if (lst->tab[0][j] == '\n' && lst->tab[0][j + 1] != '\n')
			feed_nb++;
		if (feed_nb == 4 && lst->tab[0][j] == '\n' &&
				lst->tab[0][j + 1] == '\0')
			tmp++;
		j++;
	}
	if (tmp == 1)
		return (1);
	return (0);
}

static int		check_feed_nb(t_plist *lst, int nb_tetri)
{
	int				j;
	int				feed_nb;
	static int		tmp;

	j = 0;
	feed_nb = 0;
	while (lst->tab[0][j])
	{
		if ((lst->tab[0][j] == '\n' && lst->tab[0][j + 1] != '\n') ||
				(lst->tab[0][j] == '\n' && lst->tab[0][j + 1] == '\n'))
			feed_nb++;
		if (lst->next == NULL && feed_nb == 4 &&
				lst->tab[0][j + 1] == '\0')
			tmp++;
		else if (lst->next != NULL && feed_nb == 5)
			tmp++;
		j++;
	}
	if (tmp == nb_tetri)
		return (1);
	return (0);
}

int				check_map(t_plist *lst)
{
	int			nb_tetri;
	int			ret_feed;
	int			ret_size;

	nb_tetri = ft_lstf_countnodes(lst);
	if (nb_tetri > 27)
		return (0);
	if (nb_tetri == 1)
	{
		ret_size = check_size_and_char_one_tetri(lst);
		ret_feed = check_feed_nb_one_tetri(lst);
	}
	else
	{
		while (lst != NULL)
		{
			ret_feed = check_feed_nb(lst, nb_tetri);
			ret_size = check_size_and_char(lst, nb_tetri);
			lst = lst->next;
		}
	}
	if (nb_tetri <= 26 && ret_feed == 1 && ret_size == 1)
		return (1);
	return (0);
}
