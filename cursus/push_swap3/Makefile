NAME = push_swap

CSRC = ft_push_swap.c\
	ft_push_swap_utils.c\
	ft_push_swap_utils2.c\
	ft_push_swap_pile1.c\
	ft_push_swap_pile2.c\
	ft_s_and_p.c\
	ft_r_and_rr.c\
	ft_split.c\
	ft_substr.c

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