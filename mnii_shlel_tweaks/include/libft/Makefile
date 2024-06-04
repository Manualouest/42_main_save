# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mscheman <mscheman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 14:21:30 by mscheman          #+#    #+#              #
#    Updated: 2024/03/12 00:55:29 by mscheman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

LIBFT =	LIBFT/ft_isdigit.c \
		LIBFT/ft_strchr.c \
		LIBFT/ft_strcount.c \
		LIBFT/ft_memchr.c \
		LIBFT/ft_isalnum.c \
		LIBFT/ft_strtrim.c \
		LIBFT/ft_striteri.c \
		LIBFT/ft_putnbr_fd.c \
		LIBFT/ft_calloc.c \
		LIBFT/ft_strmapi.c \
		LIBFT/ft_substr.c \
		LIBFT/ft_isspace.c \
		LIBFT/ft_isprint.c \
		LIBFT/ft_strdup.c \
		LIBFT/ft_itoa.c \
		LIBFT/ft_memcpy.c \
		LIBFT/ft_strnstr.c \
		LIBFT/ft_tolower.c \
		LIBFT/ft_isalpha.c \
		LIBFT/ft_strlcpy.c \
		LIBFT/ft_putendl_fd.c \
		LIBFT/ft_strlen.c \
		LIBFT/ft_atoi.c \
		LIBFT/ft_memset.c \
		LIBFT/ft_memcmp.c \
		LIBFT/ft_putstr_fd.c \
		LIBFT/ft_isascii.c \
		LIBFT/ft_strjoin.c \
		LIBFT/ft_strncmp.c \
		LIBFT/ft_putchar_fd.c \
		LIBFT/ft_strrchr.c \
		LIBFT/ft_split.c \
		LIBFT/ft_memmove.c \
		LIBFT/ft_bzero.c \
		LIBFT/ft_strlcat.c \
		LIBFT/ft_toupper.c \
		LIBFT/ft_strctn.c \

LIST =	LIST/ft_lstdelone_bonus.c \
		LIST/ft_lstnew_bonus.c \
		LIST/ft_lstiter_bonus.c \
		LIST/ft_lstadd_back_bonus.c \
		LIST/ft_lstclear_bonus.c \
		LIST/ft_lstlast_bonus.c \
		LIST/ft_lstadd_front_bonus.c \
		LIST/ft_lstmap_bonus.c \
		LIST/ft_lstsize_bonus.c \

LIBFT_OBJ = $(LIBFT:.c=.o)
LIST_OBJ = $(LIST:.c=.o)

PRINTF_LIB =	libftprintf.a
PRINTF_OBJ =	ft_printf.o \
				ft_printf_utils.o

GNL_LIB =	libftgnl.a
GNL_OBJ =	get_next_line_bonus.o \
			get_next_line_utils_bonus.o \
			slurp.o \

NAME = libft.a

COMPIL_FLAGS += -Wall -Wextra -Werror -c

%.o:%.c
	cc $(CC_FLAGS) $< -c -o $@

$(NAME): $(LIBFT_OBJ)
	ar rcs $(NAME) $(LIBFT_OBJ)

clean:
	rm -f $(LIBFT_OBJ)
	rm -f $(LIST_OBJ)
	make clean -C ./PRINTF
	make clean -C ./GNL

fclean: clean
	make fclean -C ./PRINTF
	make fclean -C ./GNL
	rm -f $(NAME)

all: $(NAME)

re: fclean all

list: $(LIST_OBJ)
	ar rcs $(NAME) $(LIST_OBJ)

print: $(NAME)
	make -C ./PRINTF
	mv PRINTF/$(PRINTF_LIB) -t .
	ar x $(PRINTF_LIB)
	ar rcs $(NAME) $(PRINTF_OBJ)
	rm -f $(PRINTF_OBJ)
	mv $(PRINTF_LIB) -t PRINTF/


gnl: $(NAME)
	make -C ./GNL
	mv GNL/$(GNL_LIB) -t .
	ar x $(GNL_LIB)
	ar rcs $(NAME) $(GNL_OBJ) 
	rm -f $(GNL_OBJ)
	mv $(GNL_LIB) -t GNL/

full: print gnl list $(LIBFT_OBJ)
	ar rcs $(NAME) $(LIBFT_OBJ)
