NAME = proced

CFLAGS = -Wall -Werror -Wextra -g -O3

INCLUDES = -Iincludes/ -I$(LIBMLX)/include
LIBFT = includes/libft/libft.a

LIBMLX = ./MLX42
MLX = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRC_DIR = src/
SRC = main.c

SRC += utils/tab_utils.c\
		utils/math_utils.c

SRC += inits/struct_inits.c

SRC += display/display_main.c\
		display/handle_body.c\
		display/handle_legs.c\
		display/hooks.c\
		display/utils.c

OBJ_DIR = obj/
OBJ_NAME = $(SRC:.c=.o)
OBJ = $(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))

all: libmlx $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	gcc $(CFLAGS) $< $(INCLUDES) -c -o $@

$(LIBFT) :
	@ $(MAKE) -C includes/libft all --no-print-directory

$(NAME): $(LIBFT) $(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(OBJ) $(INCLUDES) $(LIBFT) $(MLX)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

clean:
	@ $(MAKE) -C includes/libft clean --no-print-directory
	@rm -rf $(LIBMLX)/build
	rm -rf $(OBJ_DIR) $(B_OBJ_DIR)

fclean: clean
	@ $(MAKE) -C includes/libft fclean --no-print-directory
	rm -f $(NAME)

re: fclean all
