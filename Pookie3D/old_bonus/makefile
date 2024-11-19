# valgrind --suppressions=ms.supp --leak-check=full --show-leak-kinds=all ./minishell

NAME = cub3D

CFLAGS = -Wall -Werror -Wextra -g

INCLUDES = -Iincludes/ -I$(LIBMLX)/include
LIBFT = includes/libft/libft.a

# MLX
LIBMLX = ./MLX42
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Mandatory
SRC_DIR = src/
SRC_NAME = main.c\
			error.c\
			img_to_int.c\
			controllers.c

SRC_NAME += parsing/parser.c\
			parsing/check.c\
			parsing/map_handler.c

# SRC_NAME += map_maker/map_maker_main.c\
# 			map_maker/input_handler.c\
# 			map_maker/map_editor.c\
# 			map_maker/vars_setup.c\
# 			map_maker/map_setup.c\
# 			map_maker/utils.c\
# 			map_maker/img_utils.c\
# 			map_maker/setup_screens.c\
# 			map_maker/rand_gen.c

SRC_NAME += utils/tab_utils.c\
			utils/string_utils.c\
			utils/math.c

SRC_NAME += init/init_game.c\
			init/init_game_part.c

SRC_NAME += keys/keys.c\
			keys/keys_part.c

SRC_NAME += raycasting/raycast.c\
			raycasting/draw_walls.c

SRC_NAME += animactions/mooves.c

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

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	gcc $(CFLAGS) $< $(INCLUDES) -c -o $@

$(LIBFT) :
	@ $(MAKE) -C includes/libft all --no-print-directory

$(NAME): $(LIBFT) $(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(OBJ) $(INCLUDES) $(LIBFT) $(LIBS)


# $(B_OBJ_DIR)%.o:$(B_SRC_DIR)%.c
# 	@mkdir -p $(dir $@)
# 	cc $(CFLAGS) $< -c -o $@

# bonus: $(B_OBJ)
# 	@make full -C $(LIBFT_FOLDER)
# 	cc -o $(NAME) $(CFLAGS) $(B_OBJ) $(LIBFT_A) $(OTHER_LIBS)


# Opti Modes
#opti: CFLAGS += -O3
#opti: $(NAME)

# bopti: CFLAGS += -O3
# bopti: bonus


clean:
	@ $(MAKE) -C includes/libft clean --no-print-directory
	rm -rf $(OBJ_DIR) $(B_OBJ_DIR)
	# @rm -rf $(LIBMLX)/build

fclean: clean
	@ $(MAKE) -C includes/libft fclean --no-print-directory
	rm -f $(NAME)

re: fclean all

# bre: fclean bonus
