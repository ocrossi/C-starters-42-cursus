/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 14:20:35 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 17:05:57 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	t_plist		*begin;

	begin = NULL;
	if (argc != 2)
	{
		ft_putendl("usage : ./fillit test_file");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	begin = fill_the_list(fd, begin);
	if (check_parsing(begin, fd) == -1)
		exit(EXIT_FAILURE);
	we_feel_it(begin);
	ft_lstfdel_list2(begin);
	close(fd);
	exit(EXIT_SUCCESS);
	return (0);
}
