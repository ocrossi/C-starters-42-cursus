/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   place_tetriminos.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 13:33:36 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 13:49:03 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int			check_size_tetri(t_plist *current,
		t_sqs s_map, int line, int col)
{
	if ((col + current->width <= s_map.size_map) &&
			(line + current->height <= s_map.size_map))
		return (1);
	return (-1);
}

static int			*tab_init_for_place_tetri(int line, int col)
{
	int *tab;

	if (!(tab = (int*)malloc(sizeof(int) * 5)))
		return (NULL);
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = col;
	tab[3] = line;
	tab[4] = col;
	return (tab);
}

static void			norm1(int **tab, t_plist *current)
{
	if ((*tab)[1] < current->width)
	{
		(*tab)[1]++;
		(*tab)[2]++;
	}
	else
	{
		(*tab)[1] = 0;
		(*tab)[0]++;
		(*tab)[3]++;
		(*tab)[2] = (*tab)[4];
	}
}

static int			norm(int **tab, t_plist *current, t_sqs *s_map)
{
	while ((*tab)[1] < current->width)
	{
		if (current->tab[(*tab)[0]][(*tab)[1]] == '.' &&
			(*s_map).map[(*tab)[3]][(*tab)[2]] == '.')
			norm1(tab, current);
		else if (current->tab[(*tab)[0]][(*tab)[1]] == current->c &&
				(*s_map).map[(*tab)[3]][(*tab)[2]] == '.')
		{
			(*tab)[2]++;
			(*tab)[1]++;
		}
		else if (current->tab[(*tab)[0]][(*tab)[1]] == '.' &&
				ft_isalpha((*s_map).map[(*tab)[3]][(*tab)[2]]) == 1)
		{
			(*tab)[1]++;
			(*tab)[2]++;
		}
		else
			return (-1);
	}
	return (1);
}

int					check_placemap(t_plist *current, t_sqs s_map,
					int line, int col)
{
	int		*tab;

	tab = tab_init_for_place_tetri(line, col);
	if (check_size_tetri(current, s_map, line, col) < 0)
	{
		free(tab);
		tab = NULL;
		return (-1);
	}
	while (tab[0] < current->height)
	{
		if (norm(&tab, current, &s_map) == -1)
		{
			free(tab);
			tab = NULL;
			return (-1);
		}
		tab[1] = 0;
		tab[2] = tab[4];
		tab[3]++;
		tab[0]++;
	}
	free(tab);
	tab = NULL;
	return (1);
}
