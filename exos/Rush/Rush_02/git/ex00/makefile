NAME = rush-02

MY_SOURCES = ft_strfind.c dict_rush.c dict_rush2.c file_rush.c free_malloc_rush.c parsing_arg_rush.c rush.c num_modifier.c generic_rush.c ft_tab.c

CFLAGS += -Wall -Werror -Wextra

a_prog:
	(gcc -o $(NAME) $(MY_SOURCES))

clean :
	(rm $(NAME))

fclean : clean

all : a_prog

re : fclean a_prog
