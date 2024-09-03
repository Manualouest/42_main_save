# valgrind --suppressions=ms.supp --leak-check=full --show-leak-kinds=all ./minishell

NAME = cub3D

CC_FLAGS = -Wall -Werror -Wextra -g -I$(INCLUDES)
OTHER_LIBS = -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz

INCLUDES = includes/
LIBFT_FOLDER = $(INCLUDES)libft
LIBFT_A = $(INCLUDES)libft/libft.a

# Mandatory
SRC_DIR = src/
SRC_NAME = main.c\
			map_maker/map_maker_main.c\
			map_maker/input_handler.c\
			map_maker/map_editor.c

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ_DIR = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))

# # Bonus
# B_SRC_DIR = bonus/
# B_SRC_NAME = 

# B_SRC = $(addprefix $(B_SRC_DIR), $(B_SRC_NAME))

# B_OBJ_DIR = b_obj/
# B_OBJ_NAME = $(B_SRC_NAME:.c=.o)
# B_OBJ = $(patsubst %, $(B_OBJ_DIR)%, $(B_OBJ_NAME))


# Compilation
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	cc $(CC_FLAGS) $(OTHER_LIBS) $< -c -o $@

$(NAME): $(OBJ)
	make full -C $(LIBFT_FOLDER)
	make -C ./minilibx-linux
	cc -o $(NAME) $(CC_FLAGS) $(OBJ) $(LIBFT_A) $(OTHER_LIBS)

# $(B_OBJ_DIR)%.o:$(B_SRC_DIR)%.c
# 	@mkdir -p $(dir $@)
# 	cc $(CC_FLAGS) $< -c -o $@

# bonus: $(B_OBJ)
# 	@make full -C $(LIBFT_FOLDER)
# 	cc -o $(NAME) $(CC_FLAGS) $(B_OBJ) $(LIBFT_A) $(OTHER_LIBS)


# Opti Modes
opti: CC_FLAGS += -O3
opti: $(NAME)

# bopti: CC_FLAGS += -O3
# bopti: bonus


clean:
	@make clean -C $(LIBFT_FOLDER)
	@make clean -C ./minilibx-linux
	rm -rf $(OBJ_DIR) $(B_OBJ_DIR)

fclean: clean
	@make fclean -C $(LIBFT_FOLDER)
	rm -f $(NAME)

all: $(NAME)

re: fclean all

# bre: fclean bonus