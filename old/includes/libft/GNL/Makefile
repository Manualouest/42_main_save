# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mscheman <mscheman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 15:55:04 by mscheman          #+#    #+#              #
#    Updated: 2024/03/12 00:44:33 by mscheman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

GNL =	get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
		slurp.c

GNL_OBJ = $(GNL:.c=.o)

NAME = libftgnl.a

%.o:%.c
	cc $(CC_FLAGS) $< -c -o $@

$(NAME): $(GNL_OBJ)
	ar rcs $(NAME) $(GNL_OBJ)

clean:
	rm -f $(GNL_OBJ)

fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all
