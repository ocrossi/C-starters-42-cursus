/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 14:31:35 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 17:04:12 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		parsing_fillit(t_plist *begin, int fd)
{
	if (fd < 0 || BUFF_SIZE <= 0 || (read(fd, NULL, 0) == -1))
	{
		ft_putendl(ERROR);
		return (-1);
	}
	if (check_map(begin) == 0 || check_list_tetriminos(&begin) == -1)
	{
		ft_putendl(ERROR);
		return (-1);
	}
	return (1);
}

int				check_parsing(t_plist *begin, int fd)
{
	if (parsing_fillit(begin, fd) < 0)
		return (-1);
	return (1);
}
