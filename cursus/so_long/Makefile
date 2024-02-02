Name = so_long

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

Cflags = -Wall -Wextra -Werror MacroLibX/libmlx.so -lSDL2 -g

.o: .c
	clang $(Cflags) $< -c -o $@

$(Name): $(M_Obj)
	clang $(Cflags) $(M_Obj) -o $(Name)

clean:
	rm -rf $(M_Obj)

fclean: clean
	rm -rf $(Name)

all: $(Name)

re: fclean all
