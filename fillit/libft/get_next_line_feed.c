/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_feed.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/28 14:56:21 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 13:28:25 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int			read_and_get_buff(char *buff, const int fd)
{
	int					ret_read;

	ret_read = read(fd, buff, BUFF_SIZE);
	buff[ret_read] = '\0';
	return (ret_read);
}

static int			check_and_get_line_2(char **line, char *buff, const int fd,
		char **reste)
{
	int					i;
	char				*buff_tmp;

	i = 0;
	if (reste[fd])
	{
		buff_tmp = ft_strjoin(*(reste + fd), buff);
		ft_strdel(reste + fd);
	}
	else
		buff_tmp = ft_strdup(buff);
	while (buff_tmp[i] != '\n' && buff_tmp[i] != '\0')
		++i;
	if (buff_tmp[i] == '\n')
	{
		*line = ft_strsub(buff_tmp, 0, i + 1);
		*(reste + fd) = ft_strsub(buff_tmp, i + 1, ft_strlen(buff_tmp) - i);
		ft_strdel(&buff_tmp);
		return (1);
	}
	else
		*(reste + fd) = ft_strdup(buff_tmp);
	ft_strdel(&buff_tmp);
	return (0);
}

static int			check_and_get_line(char **line, char *buff, const int fd,
										char **reste)
{
	int					ret_read;

	while ((ret_read = read_and_get_buff(buff, fd)))
		while ((check_and_get_line_2(line, buff, fd, reste)))
			return (1);
	if (ret_read == 0 && reste[fd] != '\0')
	{
		if ((ft_strchr(*(reste + fd), '\n') == NULL) && *reste[fd] != '\0')
		{
			*line = ft_strdup(reste[fd]);
			ft_strdel(reste + fd);
			return (1);
		}
		else
			while ((check_and_get_line_2(line, buff, fd, reste)))
				return (1);
		ft_strdel(reste + fd);
	}
	return (0);
}

int					get_next_line_feed(const int fd, char **line)
{
	static char			*reste[4865];
	char				buff[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE <= 0 || (read(fd, NULL, 0) == -1))
		return (-1);
	while ((check_and_get_line(line, buff, fd, reste)))
		return (1);
	return (0);
}
