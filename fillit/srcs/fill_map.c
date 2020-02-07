/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/28 15:24:41 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 14:18:45 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int			find_smaller_size(t_sqs s_map)
{
	int		size;

	size = s_map.lst_nb * 4;
	while (ft_sqrt(size) == 0)
		size++;
	size = ft_sqrt(size);
	return (size);
}

char		**create_map(int nb)
{
	char	**map;
	int		lines;
	int		colonnes;
	char	*tmp;

	lines = 0;
	colonnes = 0;
	map = (char**)malloc(sizeof(char*) * (nb + 1));
	if (!map)
		return (NULL);
	map[nb] = NULL;
	tmp = ft_strnew(nb);
	while (colonnes < nb)
	{
		tmp[colonnes] = '.';
		colonnes++;
	}
	colonnes = 0;
	while (lines < nb)
	{
		map[lines] = ft_strdup(tmp);
		lines++;
	}
	ft_strdel(&tmp);
	return (map);
}

void		create_new_map(t_plist *current, t_sqs *s_map, t_plist **begin)
{
	ft_strdel((*s_map).map);
	(*s_map).map = create_map((*s_map).size_map + 1);
	(*s_map).size_map++;
	current = *begin;
	while (current->next)
	{
		current->coord[0] = 0;
		current->coord[1] = 0;
		current = current->next;
	}
	(*s_map).line = 0;
	(*s_map).col = 0;
	current = *begin;
}

int			check_empty_map(t_sqs *s_map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*s_map).map[i])
	{
		while ((*s_map).map[i][j])
		{
			if ((*s_map).map[i][j] != '.')
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
