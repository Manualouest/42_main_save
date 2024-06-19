# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mscheman <mscheman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 15:55:19 by mscheman          #+#    #+#              #
#    Updated: 2024/02/17 14:37:51 by mscheman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

SRCS =	ft_printf.c \
		ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC_FLAGS = -Wall -Werror -Wextra

%.o:%.c
	@cc $(CC_FLAGS) $< -c -o $@

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

all: $(NAME)

re: fclean all
