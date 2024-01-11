NAME = rush-02

MY_SOURCES = ft_putchar.c

CFLAGS += -Wall -Werror -Wextra

MY_OBJECTS = $(MY_SOURCES:.c=.o)

a_prog: $(MY_OBJECTS)
	$(shell gcc -o $(NAME) $(MY_SOURCES))

clean :
	(rm $(MY_OBJECTS))

fclean : clean 
	(rm $(NAME))

all : a_prog

re : fclean a_prog
