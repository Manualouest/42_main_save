NAME = push_swap

CSRC = ft_push_swap.c\
	ft_push_swap_utils.c\

HEADER = ft_push_swap.h 

COBJS = $(CSRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

%.o: %.c
	$(CC) $(CFLAGS) $< -g -c -o $@

$(NAME) : $(COBJS)
	clang -g $(COBJS) -o $(NAME)

clean:
	rm -f $(COBJS)

fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all