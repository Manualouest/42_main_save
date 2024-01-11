# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 14:46:02 by mbirou            #+#    #+#              #
#    Updated: 2023/12/13 09:37:45 by mbirou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CSRC = ft_printf.c ft_putstr_car.c ft_put_u_int.c ft_puthex.c ft_putvoid.c

HEADER = ft_printf.h 

COBJS = $(CSRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fPIC

CC = cc

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

$(NAME) : $(COBJS)
	ar rcs $(NAME) $(COBJS)

clean:
	rm -f $(COBJS)

fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all