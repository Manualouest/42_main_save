#================ COMPILATOR ================#
CC = cc
#=================== FLAGS ==================#
FLAGS = -Wall -Wextra -Werror -g -fPIE
#=================== NAME ===================#
NAME = libft.a
#============= MANDATORY SOUCES =============#
SRCS = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memmove.c \
	ft_memcpy.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_itoa.c	\
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_split.c \
	ft_free_2d_array.c \
	ft_atoi_base.c \
	ft_abs.c \
	ft_array_len.c \
	ft_unsplit.c \
	ft_multi_free.c \
	ft_multi_join.c \
	ft_join_and_free.c \
	ft_close.c \
	ft_free.c
#=============== BONUS SOURCES ==============#
BONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

#============== PRINTF SOURCES ==============#
PRINTF = ft_printf.c \
	printf_char_print.c \
	printf_nbr_print.c \
	printf_hex_print.c

#================ GNL SOURCES ===============#
GNL = gnl/get_next_line.c\
	gnl/get_next_line_utils.c

#============ TRANSFORM .c TO .o ============#
#============== MANDATORY PART ==============#
OBJM = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

#================ BONUS PART ================#
OBJB = $(addprefix $(OBJ_DIR), $(BONUS:.c=.o))

#=============== PRINTF PART ================#
OBJPR = $(addprefix $(OBJ_DIR), $(PRINTF:.c=.o))

#================ GNL PART ==================#
OBJGNL = $(addprefix $(OBJ_DIR), $(GNL:.c=.o))

OBJ_DIR = obj/

SRCS_DIR = srcs/

INCLUDE_DIR = ../

INCLUDES = -I$(INCLUDE_DIR)

#============== EXECUTABLE PART =============#

all : $(NAME)
	@echo "\033[32;47;1m** libft.a created **\033[0m"

$(NAME) : $(OBJB) $(OBJM) $(OBJPR) $(OBJGNL)
	@ar rcs $(NAME) $(OBJB) $(OBJM) $(OBJPR) $(OBJGNL)
	
$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
	@ mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)
	@echo "\033[32;47;1m** cleaned **\033[0m"

fclean :
	@rm -rf $(NAME) $(OBJ_DIR)
	@echo "\033[32;47;1m** fcleaned **\033[0m"

re : fclean all

.PHONY : all clean fclean re
