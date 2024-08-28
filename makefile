# valgrind --suppressions=ms.supp --leak-check=full --show-leak-kinds=all ./minishell

NAME = cub3D

CC_FLAGS = -Wall -Werror -Wextra -g -I$(INCLUDES) -Imlx_linux
OTHER_LIBS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

INCLUDES = includes/
LIBFT_FOLDER = $(INCLUDES)libft
LIBFT_A = $(INCLUDES)libft/libft.a

# Mandatory
SRC_DIR = src/
SRC_NAME = main.c\
			struct_setup/struct_setup_main.c\
			struct_setup/struct_setup_utils.c\
			struct_setup/mlx_setup.c\
			struct_setup/clean_map.c\
			frees/free_struct.c\
			math_utils/color_utils.c\
			hooks/hook_setup.c\
			hooks/handle_background.c\
			hooks/raycast.c\
			hooks/minimap.c\
			hooks/handle_mouse.c\
			hooks/handle_mining.c\
			hooks/minimap_editor.c

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ_DIR = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))

# Bonus
B_SRC_DIR = bonus/
B_SRC_NAME = main.c\
			struct_setup/struct_setup_main.c\
			struct_setup/struct_setup_utils.c\
			struct_setup/mlx_setup.c\
			struct_setup/clean_map.c\
			frees/free_struct.c\
			math_utils/color_utils.c\
			hooks/hook_setup.c\
			hooks/handle_background.c\
			hooks/raycast.c\
			hooks/minimap.c\
			hooks/handle_mouse.c\
			hooks/handle_mining.c\
			hooks/minimap_editor.c

B_SRC = $(addprefix $(B_SRC_DIR), $(B_SRC_NAME))

B_OBJ_DIR = b_obj/
B_OBJ_NAME = $(B_SRC_NAME:.c=.o)
B_OBJ = $(patsubst %, $(B_OBJ_DIR)%, $(B_OBJ_NAME))


# Compilation
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	cc $(CC_FLAGS) $< -c -o $@

$(NAME): $(OBJ)
	@make full -C $(LIBFT_FOLDER)
	cc -o $(NAME) $(CC_FLAGS) $(OBJ) $(LIBFT_A) $(OTHER_LIBS)

$(B_OBJ_DIR)%.o:$(B_SRC_DIR)%.c
	@mkdir -p $(dir $@)
	cc $(CC_FLAGS) $< -c -o $@

bonus: $(B_OBJ)
	@make full -C $(LIBFT_FOLDER)
	cc -o $(NAME) $(CC_FLAGS) $(B_OBJ) $(LIBFT_A) $(OTHER_LIBS)


# Opti Modes
opti: CC_FLAGS += -O3
opti: $(NAME)

bopti: CC_FLAGS += -O3
bopti: bonus


clean:
	@make clean -C $(LIBFT_FOLDER)
	rm -rf $(OBJ_DIR) $(B_OBJ_DIR)

fclean: clean
	@make fclean -C $(LIBFT_FOLDER)
	rm -f $(NAME)

all: $(NAME)

re: fclean all

bre: fclean bonus