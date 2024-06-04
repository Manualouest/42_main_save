NAME = libft.a

CSRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c

HEADER = libft.h 

COBJS = $(CSRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(COBJS)
	ar rcs $(NAME) $(COBJS)

clean:
	rm -f $(COBJS)

fclean: clean
	rm -f $(NAME)

all: $(NAME)
	cat all

re: fclean all