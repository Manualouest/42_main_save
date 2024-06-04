
NAME = mini_shell

CC_FLAGS = -Wall -Werror -Wextra -g -I$(INCLUDES)
OTHER_LIBS = -lreadline -lncurses

INCLUDES = include/
LIBFT_FOLDER = $(INCLUDES)libft
LIBFT_A = $(INCLUDES)libft/libft.a

SRC_DIR = src/
SRC_NAME = ms_main.c\
			signal_handling.c

SRC_NAME +=	parsing/ms_parsing_pre_execheck_main.c\
			parsing/ms_cd_pre_execheck.c\
			parsing/ms_unset_pre_execheck.c\
			parsing/ms_exit_pre_execheck.c\
			parsing/ms_params_pre_execheck.c
SRC_NAME +=	tokeniser/ms_tokeniser_cmd.c\
			tokeniser/ms_tokeniser_main.c\
			tokeniser/ms_tokeniser_params.c\
			tokeniser/ms_tokeniser_utils.c\
			tokeniser/ms_tokeniser_free.c\
			tokeniser/ms_tokeniser_env_modifs.c\
			tokeniser/ms_tokeniser_redirect_cleaner.c\
			tokeniser/ms_heredoc.c
SRC_NAME +=	structure_translator/ms_structure_translator_main.c\
			structure_translator/ms_cmd_free.c

SRC_NAME +=	env_handler/ms_env_var.c \
			env_handler/ms_env_utils_1.c \
			env_handler/ms_env_utils_2.c \
			env_handler/ms_env_builtins.c
SRC_NAME += commands/ms_exit.c \
			commands/ms_echo.c \
			commands/ms_cd.c
SRC_NAME += execution/ms_exec.c \
			execution/ms_exec_utils.c \
			execution/ms_exec_initfds.c 

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