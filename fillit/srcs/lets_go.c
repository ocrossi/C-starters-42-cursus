/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lets_go.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 14:10:57 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 16:56:37 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void		del_map(t_sqs *s_map)
{
	int i;

	i = 0;
	while (s_map->map[i])
	{
		ft_strdel(&(s_map->map[i]));
		i++;
	}
	free(s_map->map);
	s_map->map = NULL;
}

void		we_feel_it(t_plist *begin)
{
	t_plist		*tmp;
	t_sqs		s_map;

	tmp = begin;
	switch_to_char(tmp);
	switch_to_2d(&tmp);
	find_height_and_width(tmp);
	move_all_tetri_up_left(tmp);
	tmp = begin;
	s_map.nb = 0;
	s_map.lst_nb = ft_lstf_countnodes(begin);
	s_map.size_map = find_smaller_size(s_map);
	s_map.map = create_map(s_map.size_map);
	s_map.line = 0;
	s_map.col = 0;
	big_function(&tmp, &s_map, &begin);
	del_map(&s_map);
}
