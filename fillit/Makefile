CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

# LIB #

NAME_LIB = libft.a
PATH_LIB = ./libft/

# VARS LOCALES #

NAME = fillit
PATH_SRCS = ./srcs/
PATH_OBJ = ./obj/
PATH_INC = ./includes/
FILES = $(shell ls srcs | cut -d . -f 1)
SRC = $(addprefix $(PATH_SRCS), $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(PATH_OBJ), $(addsuffix .o, $(FILES)))
INC =  $(addprefix $(PATH_INC), fillit.h)
MAIN = main.c

# RULES #

all : $(NAME)

$(NAME): $(PATH_LIB)$(NAME_LIB) $(PATH_OBJ) $(OBJ)
	$(CC) $(CC_FLAGS) -L $(PATH_LIB) -I $(PATH_INC) $(OBJ) $(PATH_LIB)$(NAME_LIB) $(MAIN) -o $(NAME)

$(PATH_LIB)$(NAME_LIB):
	make -C $(PATH_LIB)


$(PATH_OBJ):
	mkdir $(PATH_OBJ)

$(PATH_OBJ)%.o: $(PATH_SRCS)%.c $(INC)
	$(CC) $(CC_FLAGS) -I $(PATH_LIB) -I $(PATH_INC) -o $@ -c $< 

clean:
	make -C $(PATH_LIB) clean
	rm -f $(OBJ)

fclean : clean
	make -C $(PATH_LIB) fclean
	rm -rf $(PATH_OBJ)
	rm $(NAME)

re : fclean all
