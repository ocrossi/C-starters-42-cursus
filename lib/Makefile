# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ocrossi <ocrossi@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/02 17:05:45 by ocrossi      #+#   ##    ##    #+#        #
#    Updated: 2018/10/30 18:19:12 by ocrossi     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

FILES = ft_memcpy.c \
	ft_strncat.c\
	ft_strlcat.c\
	ft_memmove.c\
	ft_memset.c\
	ft_strcpy.c\
	ft_strncpy.c\
	ft_bzero.c\
	ft_memccpy.c\
	ft_strdup.c\
	ft_strndup.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strcat.c\
	ft_strlen.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strstr.c\
	ft_strnstr.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_isalpha.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strnew.c\
	ft_strdel.c\
	ft_strclr.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strequ.c\
	ft_strnequ.c\
	ft_strtrim.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_putendl.c\
	ft_putnbr.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_itoa.c\
	ft_count_integer.c\
	ft_memdel.c\
	ft_strsub.c\
	ft_strjoin.c\
	ft_memalloc.c\
	ft_strsplit.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_putstr_2d.c\
	ft_str_islower.c\
	ft_str_isupper.c\
	ft_lstprint.c\
	ft_lstprintone.c\
	ft_sqrt.c\
	print_memory.c print_memory2.c\
	get_next_line.c option_managment.c option_utils.c options.c options2.c options3.c print.c print_binary.c print_memory.c print_memory2.c scan_format.c scan_options.c sprint.c type_functions1.c type_functions2.c type_functions_utils.c utils.c \
	ft_litoa.c base_calculus.c floating_points.c ft_count_lnumber.c ft_strcapitalize.c 


FLAGS = -Wall -Wextra -Werror

PATH_PF = ./printf/

PFL = libft_printf.a

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(PATH_PF)$(PFL)
	ar rcs $(NAME) $(OBJ)

%.o: %.c libft.h
	gcc $(FLAGS) -I libft.h -I ft_printf.h -c $*.c

$(PATH_PF)$(PFL):
	make -C $(PATH_PF)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
