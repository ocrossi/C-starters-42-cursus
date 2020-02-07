#*************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/04 15:46:23 by ztrouill     #+#   ##    ##    #+#        #
#    Updated: 2018/12/19 08:47:34 by ztrouill    ###    #+. /#+    ###.fr      #
#    Updated: 2018/11/27 14:14:28 by ztrouill    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #


NAME = libft.a

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	   ft_memchr.c ft_memcmp.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
	   ft_strcat.c ft_strncat.c  ft_strlcat.c ft_strchr.c ft_strrchr.c \
	   ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strstr.c ft_strnstr.c \
	   ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
	   ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	   ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	   ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	   ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
	   ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_sqrt.c ft_swap.c \
	   ft_int_len.c ft_putstr_2d.c ft_recursive_factorial.c \
	   get_next_line.c get_next_line_feed.c \
	   ft_swap_col.c ft_swap_line.c

OBJ = $(SRCS:.c=.o)


INCLUDE = libft.h

%.o : %.c $(INCLUDE)
	gcc $(FLAGS) $< -o $@

FLAGS = -Wall -Wextra -Werror -c

all : $(NAME)

$(NAME) : $(OBJ)
	ar rus $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
