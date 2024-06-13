# valgrind --suppressions=ms.supp --leak-check=full --show-leak-kinds=all ./minishell

NAME = minishell

CC_FLAGS = -Wall -Werror -Wextra -g -I$(INCLUDES)
OTHER_LIBS = -lreadline -lncurses

INCLUDES = include/
LIBFT_FOLDER = $(INCLUDES)libft
LIBFT_A = $(INCLUDES)libft/libft.a

SRC_DIR = src/
SRC_NAME = tokeniser_main_test.c

SRC_NAME +=	parsing/ms_parsing_pre_execheck_main.c\
			parsing/ms_cd_pre_execheck.c\
			parsing/ms_unset_pre_execheck.c\
			parsing/ms_exit_pre_execheck.c\
			parsing/ms_params_pre_execheck.c\
			parsing/ms_redirect_checking.c

SRC_NAME +=	tokeniser/ms_tokeniser_main.c\
			tokeniser/ms_first_setup.c\
			tokeniser/ms_setups_utils.c\
			tokeniser/ms_second_setup.c

SRC_NAME +=	structure_translator/ms_structure_translator_main.c\

SRC_NAME += env/ms_tab_tools.c

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ_DIR = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@)
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
