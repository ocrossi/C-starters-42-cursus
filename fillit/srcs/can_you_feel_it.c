/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   can_you_feel_it.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 12:31:14 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 14:04:46 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		end_map(t_plist **current, t_sqs *s_map)
{
	if ((*current)->c != 'A')
		*current = (*current)->prev;
	remove_tetriminos((*current)->coord[0], (*current)->coord[1],
			s_map, *current);
	(*s_map).nb--;
	if ((*current)->c == 'A' &&
			(*current)->coord[0] == (*s_map).size_map - (*current)->height &&
			(*current)->coord[1] == (*s_map).size_map - (*current)->width)
		return (-1);
	if ((*current)->coord[1] == (*s_map).size_map - 1)
	{
		(*current)->coord[1] = 0;
		(*s_map).col = (*current)->coord[1];
		(*current)->coord[0]++;
		(*s_map).line = (*current)->coord[0];
	}
	else
	{
		(*current)->coord[1]++;
		(*s_map).col = (*current)->coord[1];
		(*s_map).line = (*current)->coord[0];
	}
	return (0);
}

static void		find_place(t_plist **current, t_sqs *s_map)
{
	if ((*s_map).lst_nb == 1)
		return ;
	while (check_placemap(*current, *s_map, (*s_map).line, (*s_map).col) == -1)
	{
		if ((*s_map).col == (*s_map).size_map - 1 &&
				(*s_map).line < (*s_map).size_map - 1)
		{
			(*s_map).col = 0;
			(*s_map).line++;
		}
		else if ((*s_map).col < (*s_map).size_map - 1)
			(*s_map).col++;
		if ((*s_map).col == (*s_map).size_map - 1 &&
				(*s_map).line == (*s_map).size_map - 1)
			if ((*s_map).lst_nb != 1)
				if (end_map(current, s_map) == -1)
					break ;
	}
}

static int		can_you_feel_it(t_plist **current, t_sqs *s_map,
		t_plist **begin)
{
	while ((*s_map).nb != (*s_map).lst_nb)
	{
		if ((*s_map).nb == (*s_map).lst_nb)
			return (0);
		if (check_placemap(*current, *s_map, (*s_map).line, (*s_map).col) == 1)
		{
			print_tetriminos((*s_map).line, (*s_map).col, s_map, *current);
			(*current)->coord[0] = (*s_map).line;
			(*current)->coord[1] = (*s_map).col;
			if ((*s_map).lst_nb != 1)
				*current = (*current)->next;
			(*s_map).nb++;
			can_you_feel_it(current, s_map, begin);
		}
		else
		{
			if ((*s_map).nb == (*s_map).lst_nb)
				break ;
			return (-1);
		}
	}
	return (0);
}

int				big_function(t_plist **tmp, t_sqs *s_map, t_plist **begin)
{
	while ((can_you_feel_it(tmp, s_map, begin)) != 0)
	{
		(*s_map).line = 0;
		(*s_map).col = 0;
		if (check_empty_map(s_map) == 1)
		{
			del_map(s_map);
			create_new_map(*tmp, s_map, begin);
		}
		find_place(tmp, s_map);
	}
	ft_putstr_2d((*s_map).map);
	return (1);
}
