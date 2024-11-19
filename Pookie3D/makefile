NAME = cub3d

B_NAME = pookie3d

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
			img_to_int.c

SRC_NAME += parsing/parser.c\
			parsing/check.c\
			parsing/map_handler.c

SRC_NAME += utils/tab_utils.c\
			utils/string_utils.c\
			utils/math.c

SRC_NAME += init/init_game.c\
			init/init_game_part.c

SRC_NAME += keys/keys.c\
			keys/keys_part.c

SRC_NAME += raycasting/raycast.c\
			raycasting/draw_walls.c

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ_DIR = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))

# Bonus
B_SRC_DIR = bonus/src/

B_SRC_NAME = main.c\
			error.c\
			img_to_int.c

B_SRC_NAME += gui/gui_setup.c\
				gui/minimap.c

B_SRC_NAME += init/init_structs.c\
			init/init_tabs.c

B_SRC_NAME += keys/keys.c\
			keys/keys_part.c\
			keys/wall_edition.c\
			keys/camera.c\
			keys/controllers.c\
			keys/jump.c

B_SRC_NAME += parsing/parser.c\
			parsing/check.c\
			parsing/map_handler.c

B_SRC_NAME += raycasting/raycast.c\
			raycasting/draw_walls.c\
			raycasting/make_tiles.c\
			raycasting/utils.c\
			raycasting/sprites.c\
			raycasting/sprite_list_utils.c\
			raycasting/door_raycast.c

B_SRC_NAME += utils/tab_utils.c\
			utils/string_utils.c\
			utils/math.c\
			utils/array_utils.c

B_SRC = $(addprefix $(B_SRC_DIR), $(B_SRC_NAME))

B_OBJ_DIR = b_obj/
B_OBJ_NAME = $(B_SRC_NAME:.c=.o)
B_OBJ = $(patsubst %, $(B_OBJ_DIR)%, $(B_OBJ_NAME))

# Compilation

all: mlx $(NAME)

mlx :
	@if ls | grep -q "MLX42"; then \
		clear; \
		echo "\033[32;47;1m** MLX42 already exist **\033[1;m"; \
	else \
		git clone https://github.com/codam-coding-college/MLX42.git; \
		cmake ./MLX42 -B ./MLX42/build; \
		make -C ./MLX42/build --no-print-directory -j4; \
		make --directory ./MLX42/build; \
	fi

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@gcc $(CFLAGS) $< $(INCLUDES) -c -o $@

$(B_OBJ_DIR)%.o:$(B_SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@gcc $(CFLAGS) $< $(INCLUDES) -c -o $@

$(LIBFT) :
	@ make -C includes/libft all --no-print-directory

$(NAME): mlx $(LIBFT) $(OBJ)
	@gcc -o $(NAME) $(CFLAGS) $(OBJ) $(INCLUDES) $(LIBFT) $(LIBS)
	@echo "\033[32;47;1m** FINISH **\033[1;m"

bonus: mlx  $(LIBFT) $(B_OBJ)
	@gcc -o $(B_NAME) $(CFLAGS) $(B_OBJ) $(INCLUDES) $(LIBFT) $(LIBS)
	@echo "\033[32;47;1m** FINISH BONUS **\033[1;m"

bfast: mlx  $(LIBFT) $(B_OBJ)
	@gcc -o $(B_NAME) -Ofast $(CFLAGS) $(B_OBJ) $(INCLUDES) $(LIBFT) $(LIBS)
	@echo "\033[32;47;1m** FINISH BONUS **\033[1;m"

clean:
	@ make -C includes/libft clean --no-print-directory
	rm -rf $(OBJ_DIR) $(B_OBJ_DIR)

fclean: clean
	@ make -C includes/libft fclean --no-print-directory
	rm -f $(NAME) $(B_NAME)

re: fclean all

end: 
	rm -rf MLX42

bruh: fclean bonus
