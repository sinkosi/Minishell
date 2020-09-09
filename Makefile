NAME = minishell

SRC = ./sources/main.c ./sources/search_par.c ./sources/arr_dup.c \
		./sources/arr_len.c ./sources/arr_delete.c ./sources/arr_realloc.c \
		./sources/ft_setenv.c ./sources/ft_unsetenv.c ./sources/errors.c \
		./sources/cmd_cd.c ./sources/parser.c ./sources/explode.c ./sources/cmd_echo.c \
		./sources/print_env.c ./sources/permission_err.c

OBJ = main.o search_par.o arr_dup.o arr_len.o arr_delete.o \
		arr_realloc.o ft_setenv.o ft_unsetenv.o errors.o cmd_cd.o \
		parser.o explode.o cmd_echo.o print_env.o permission_err.o

FLAGS = -Wall -Werror -Wextra

LIB = ./libft/libft.a

all: $(NAME)

$(NAME):
	@make -C libft/ libft.a
	gcc $(FLAGS) -c $(SRC) -g
	gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

libft:
	make -C libft/ libft.a

clean:
	make -C libft/ clean
	rm -fr $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -fr $(NAME)

re: fclean all




