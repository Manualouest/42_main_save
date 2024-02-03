Name = so_long
LIBMLX = ./MLX42

Header = -I sl_include.h -I $(LIBMLX)/include
Libs = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
M_Src = sl_parsing_main.c\
	sl_free_error.c\
	sl_main.c\
	sl_stack_handler.c

Extras = $(addprefix extras/,\
	get_next_line.c\
	get_next_line_utils.c\
	ft_split.c\
	ft_substr.c)

M_Obj = $(M_Src:.c=.o) $(Extras:.c=.o)

Cflags = -Wall -Wextra -Werror -g

all: libmlx $(Name)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	clang $(Cflags) $(Header) $< -c -o $@

$(Name): $(M_Obj)
	clang $(Cflags) $(M_Obj) $(Libs) $(Header) -o $(Name)

clean:
	rm -rf $(M_Obj)
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(Name)


re: fclean all
