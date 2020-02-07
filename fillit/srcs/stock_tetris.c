/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stock_tetris.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 13:57:27 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 10:42:59 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int						stock_tetris(const int fd, t_plist *current)
{
	char			*line;
	char			*tmp;
	int				i;
	int				ret;

	line = NULL;
	i = 0;
	while ((ret = get_next_line_feed(fd, &line)) > 0)
	{
		tmp = ft_strdup(current->tab[0]);
		free(current->tab[0]);
		i++;
		current->tab[0] = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		if (i == 5)
			break ;
	}
	if (i == 5)
		return (1);
	if (i == 4)
		return (2);
	return (0);
}

static void				init_values(int pcoord[2], int psize[2], char *pc,
		int *peof)
{
	*peof = 0;
	pcoord[0] = 0;
	pcoord[1] = 0;
	psize[0] = 0;
	psize[1] = 0;
	*pc = 'A';
}

static void				fill_first_elem(int fd, int *peof, char *pc,
		t_plist **begin)
{
	int				coord[2];
	int				size[2];
	t_plist			*current;

	coord[0] = 0;
	coord[1] = 0;
	size[0] = 0;
	size[1] = 0;
	current = ft_lstfnew("", *pc, size, coord);
	*peof = stock_tetris(fd, current);
	*begin = current;
	current = NULL;
	*pc = 'B';
}

t_plist					*fill_the_list(const int fd, t_plist *begin)
{
	t_plist			*current;
	int				coord[2];
	int				size[2];
	char			c;
	int				eof;

	init_values(coord, size, &c, &eof);
	while (c != 91)
	{
		if (c == 'A')
			fill_first_elem(fd, &eof, &c, &begin);
		else
		{
			if (eof == 2)
				break ;
			current = ft_lstfnew("", c, size, coord);
			eof = stock_tetris(fd, current);
			ft_lstfaddend(&begin, current);
			if (eof != 2)
				current = current->next;
			c++;
		}
	}
	return (begin);
}
