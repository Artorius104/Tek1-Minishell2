##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## minishell1
##

PATH_SRC        =       src/

PATH_LIB        =       lib/my/

LIB     = -L./lib -lmy

CRITERION_FLAGS =       --coverage -lcriterion

CPPFLAGS = -I./include

CFLAGS  =       -W -Wall -Wextra -g3

CC = gcc

NAME    =       mysh

SRC_MAIN        =       $(PATH_SRC)main.c       \

SRC             =       $(PATH_SRC)get_line.c	\
						$(PATH_SRC)str_to_arr.c	\
						$(PATH_SRC)exec_cmd.c	\
						$(PATH_SRC)exec_my_cmd.c	\
						$(PATH_SRC)utils.c	\
						$(PATH_SRC)do_env.c	\
						$(PATH_SRC)do_setenv.c	\
						$(PATH_SRC)do_unsetenv.c	\
						$(PATH_SRC)do_exit.c	\
						$(PATH_SRC)do_cd.c	\
						$(PATH_SRC)redir.c	\
						$(PATH_SRC)pipe.c	\

TEST_NAME       =       unit_tests

PATH_TESTS      =       tests/

SRC_TESTS       =       \

OBJ     =       $(SRC:.c=.o) $(SRC_MAIN:.c=.o)

all:    $(NAME)

$(NAME):    $(OBJ)
		make -C ./$(PATH_LIB)
		$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $(NAME) $(LIB)
		rm -f $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		make fclean -C $(PATH_LIB)
		rm -f $(NAME)
		rm -f $(TEST_NAME)
		rm -f *.gcda
		rm -f *.gcno

re:             fclean all

debug:
		$(CFLAGS) += -ggdb
		$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $(NAME) $(LIB)

tests_run:
		rm -f *.gcda
		rm -f *.gcno
		$(CC) -o $(TEST_NAME) $(CFLAGS) $(CPPFLAGS) $(SRC) tests/*.c $(CRITERION_FLAGS)
		./$(TEST_NAME)

.PHONY: clean fclean re all tests_run
