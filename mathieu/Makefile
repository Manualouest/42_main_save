
NAME = minishell

CC_FLAGS = -Wall -Werror -Wextra -g -I$(INCLUDES)
OTHER_LIBS = -lreadline -lncurses

INCLUDES = include/
LIBFT_FOLDER = $(INCLUDES)libft
LIBFT_A = $(INCLUDES)libft/libft.a

SRC_DIR = src/
SRC_NAME = ms_main.c\
			signal_handling.c

SRC_NAME +=	tokeniser/ms_tokeniser_main.c\
			tokeniser/ms_first_setup.c\
			tokeniser/ms_setups_utils.c\
			tokeniser/ms_second_setup.c\
			tokeniser/ms_redirect_append_setup.c

SRC_NAME += builtins/ms_cd.c \
			builtins/ms_pwd.c \
			builtins/ms_echo.c \
			builtins/ms_env.c \
			builtins/ms_exit.c \
			builtins/ms_unset.c \
			builtins/ms_export.c \
			builtins/ms_export_noarg.c
SRC_NAME += env/ms_tab_tools.c
SRC_NAME += execution/ms_exec.c \
			execution/ms_exec_pipe.c \
			execution/ms_exec_utils.c \
			execution/ms_exec_initfds.c \
			execution/ms_exec_builtins.c

# to remove
SRC_NAME += tokeniser_main_test.c



SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ_DIR = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	cc $(CC_FLAGS) $< -c -o $@

$(OBJ_DIR)%.o:$(BONUS_DIR)%.c
	cc $(CC_FLAGS) $< -c -o $@

$(NAME): $(OBJ)
	@make full -C $(LIBFT_FOLDER)
	cc -o $(NAME) $(OBJ) $(LIBFT_A) $(OTHER_LIBS)

clean:
	@make clean -C $(LIBFT_FOLDER)
	rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIBFT_FOLDER)
	rm -f $(NAME)

all: $(NAME)

re: fclean all
