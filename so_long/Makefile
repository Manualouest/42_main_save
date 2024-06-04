Name = so_long
B_Name = so_long_bonus
LIBMLX = ./MLX42

Header = -I sl_include.h -I ./Bonus/sl_include_bonus.h -I $(LIBMLX)/include
Libs = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
M_Src = sl_parsing_main.c\
	sl_free_error.c\
	sl_main.c\
	sl_stack_handler.c\
	sl_special_handlers.c\
	sl_in_game_updaters.c\
	sl_texture_handler.c\
	sl_texture_handler1.c\
	sl_texture_handler2.c\
	sl_texture_handler3.c\
	sl_texture_handler4.c\
	sl_texture_handler5.c\
	utils.c

B_Src = $(addprefix Bonus/,\
	sl_bees_handler_utils_bonus.c\
	sl_bees_handler_bonus.c\
	sl_counter_handler_bonus.c\
	sl_end_gif_utils_bonus.c\
	sl_end_gif_setup_bonus.c\
	sl_free_error_bonus.c\
	sl_hive_setup_bonus.c\
	sl_hive_setup_utils_bonus.c\
	sl_gif_mover_bonus.c\
	sl_setup_struct_bonus.c\
	sl_setup_images_bonus.c\
	sl_parsing_bonus.c\
	sl_stack_handler_bonus.c\
	sl_misc_handlers_bonus.c\
	sl_animations_bonus.c\
	sl_animations_utils_bonus.c\
	sl_texture_handler_bonus.c\
	sl_texture_handler1_bonus.c\
	sl_texture_handler2_bonus.c\
	sl_texture_handler3_bonus.c\
	sl_texture_handler4_bonus.c\
	sl_texture_handler5_bonus.c\
	sl_hive_handler_bonus.c\
	sl_setup_utils_bonus.c\
	sl_handle_sounds_bonus.c\
	sl_math_utils_bonus.c\
	sl_other_utils_bonus.c)

Extras = $(addprefix extras/,\
	get_next_line.c\
	get_next_line_utils.c\
	ft_split.c\
	ft_substr.c\
	ft_itoa.c)

M_Obj = $(M_Src:.c=.o) $(Extras:.c=.o)
B_Obj = $(B_Src:.c=.o) $(Extras:.c=.o)

Cflags = -Wall -Wextra -Werror -g

all: libmlx $(Name)

bonus: libmlx $(B_Name)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	clang $(Cflags) $(Header) $< -c -o $@

$(Name): $(M_Obj)
	clang $(Cflags) $(M_Obj) $(Libs) $(Header) -o $(Name)

$(B_Name): $(B_Obj)
	clang $(Cflags) $(B_Obj) $(Libs) $(Header) -o $(B_Name)

clean:
	rm -rf $(M_Obj)
	rm -rf $(B_Obj)
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(Name)
	rm -rf $(B_Name)


re: fclean all
