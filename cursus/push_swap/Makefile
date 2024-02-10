NAME = push_swap
BNAME = checker


COMMON_SRC = ft_push_swap_utils.c\
	ft_push_swap_utils2.c\
	ft_push_swap_utils3.c\
	ft_push_swap_utils4.c\
	ft_push_swap_pile1.c\
	ft_push_swap_pile2.c\
	ft_s_and_p.c\
	ft_r_and_rr.c\
	ft_split.c\
	ft_substr.c\
	ft_push_swap_index_finders.c\
	ft_push_swap_algo_utils.c

SRC = ft_push_swap.c

BSRC = ./GNL/get_next_line.c\
	./GNL/get_next_line_utils.c\
	ft_checker_bonus.c\
	ft_checker_utils_bonus.c

OBJS = $(SRC:.c=.o) $(COMMON_SRC:.c=.o)
BOBJS = $(BSRC:.c=.o) $(COMMON_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	clang $(CFLAGS) $< -g -c -o $@

$(NAME) : $(OBJS)
	clang -g $(OBJS) -o $(NAME)
	clear
	@echo "Done :)"

bonus: all $(BNAME)

$(BNAME) : $(BOBJS)
	clang -g $(BOBJS) -o $(BNAME)
	clear
	@echo "Done Bonus :)"

clean:
	rm -f $(OBJS)
	rm -f $(BOBJS)
	clear
	@echo "Cleaned :)"

fclean: clean
	rm -f $(NAME)
	rm -f $(BNAME)
	clear
	@echo "Fcleaned :)"

all: $(NAME)

re: fclean all
