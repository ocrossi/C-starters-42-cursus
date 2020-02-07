/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:07:46 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 14:04:37 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

# define ERROR "error"

typedef struct		s_sqs
{
	char			**map;
	int				size_map;
	int				lst_nb;
	int				nb;
	int				line;
	int				col;
}					t_sqs;

typedef struct		s_flist
{
	char			c;
	char			**tab;
	int				height;
	int				width;
	int				size[2];
	int				coord[2];
	struct s_flist	*next;
	struct s_flist	*prev;
}					t_plist;
/*
** Fonctions de listes
*/
t_plist				*ft_lstfnew(char *tab, char c, int size[2], int coord[2]);
void				ft_lstfaddend(t_plist **begin, t_plist *ne);
int					ft_lstf_countnodes(t_plist *begin);
void				ft_lstfdelone(t_plist **current, void (*del_elem)(char c,
			char **tab, int height, int width), void (*del_elem2)
		(int size[2], int coord[2]));
void				ft_lstfdel_list2(t_plist *begin);
/*
** Fonctions manipulation des tetriminos
*/
t_plist				*fill_the_list(const int fd, t_plist *begin);
void				switch_to_char(t_plist *lst);
void				switch_to_2d(t_plist **begin);
void				find_height_and_width(t_plist *lst);
int					find_col_3x2(t_plist *lst, int line, int col);
void				move_all_tetri_up_left(t_plist *lst);
void				find_height(t_plist *lst);
void				find_width(t_plist *lst);
void				del_elem(char c, char **tab, int height, int width);
void				del_elem2(int size[2], int coord[2]);
/*
**	Fonctions des gestion des erreurs
*/
int					check_list_tetriminos(t_plist **begin);
int					check_map(t_plist *lst);
int					check_parsing(t_plist *begin, int fd);
/*
** Fonctions de check et placement des pieces sur la map
*/
char				**create_map(int nb);
void				create_new_map(t_plist *current, t_sqs *s_map,
					t_plist **begin);
int					check_empty_map(t_sqs *s_map);
int					find_smaller_size(t_sqs s_map);
int					check_placemap(t_plist *current, t_sqs s_map,
					int line, int col);
void				print_tetriminos(int line, int col, t_sqs *s_map,
					t_plist *current);
void				remove_tetriminos(int line, int col, t_sqs *s_map,
					t_plist *current);
int					big_function(t_plist **tmp, t_sqs *s_map, t_plist **begin);
void				del_map(t_sqs *s_map);
/*
** Fonction initialisation
*/
void				we_feel_it(t_plist *begin);

#endif
