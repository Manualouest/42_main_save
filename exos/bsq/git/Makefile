NAME = bsq

CSRC = src/find_square.c src/main.c src/map_line_info.c src/map_parsing.c \
src/str.c src/utilitary.c src/utilitary2.c

HEADER = includes/utils.h includes/str.h

INC = includes

COBJS = $(CSRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -I$(INC) 

all:$(NAME)

$(NAME): $(COBJS)
	cc $(COBJS) $(LDFLAGS) -o $(NAME)

%.o : %.c $(HEADER)
	cc $(CFLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(COBJS)

re: fclean all
