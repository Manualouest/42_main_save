NAME = libft.a

INCLUDE = include/

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE)

M_SRC = part1/ft_isalpha.c\
	part1/ft_isdigit.c\
	part1/ft_isalnum.c\
	part1/ft_isascii.c\
	part1/ft_isprint.c\
	part1/ft_strlen.c\
	part1/ft_memset.c\
	part1/ft_bzero.c\
	part1/ft_memcpy.c\
	part1/ft_memmove.c\
	part1/ft_strlcpy.c\
	part1/ft_strlcat.c\
	part1/ft_toupper.c\
	part1/ft_tolower.c\
	part1/ft_strchr.c\
	part1/ft_strrchr.c\
	part1/ft_strncmp.c\
	part1/ft_memchr.c\
	part1/ft_memcmp.c\
	part1/ft_strnstr.c\
	part1/ft_atoi.c\
	part1/ft_calloc.c\
	part1/ft_strdup.c\
	part2/ft_substr.c\
	part2/ft_strjoin.c\
	part2/ft_strtrim.c\
	part2/ft_split.c\
	part2/ft_itoa.c\
	part2/ft_strmapi.c\
	part2/ft_striteri.c\
	part2/ft_putchar_fd.c\
	part2/ft_putstr_fd.c\
	part2/ft_putendl_fd.c\
	part2/ft_putnbr_fd.c

B_SRC = bonus/ft_lstnew_bonus.c\
	bonus/ft_lstadd_front_bonus.c\
	bonus/ft_lstsize_bonus.c\
	bonus/ft_lstlast_bonus.c\
	bonus/ft_lstadd_back_bonus.c\
	bonus/ft_lstdelone_bonus.c\
	bonus/ft_lstclear_bonus.c\
	bonus/ft_lstiter_bonus.c\
	bonus/ft_lstmap_bonus.c

M_OBJS = $(addprefix obj/, $(M_SRC:.c=.o))

B_OBJS = $(addprefix obj/, $(B_SRC:.c=.o))

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) $< -c -o $@

$(NAME) : $(M_OBJS)
	@mkdir -p $(dir $@)
	ar rcs $(NAME) $(M_OBJS)

bonus: $(M_OBJS) $(B_OBJS)
	ar rcs $(NAME) $(M_OBJS) $(B_OBJS)

clean:
	rm -rf obj/
	# rm -f $(M_OBJS)
	# rm -f $(B_OBJS)

fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all
