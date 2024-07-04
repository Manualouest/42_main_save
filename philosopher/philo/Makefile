NAME = philo

FLAGS = -Wall -Werror -Wextra -pthread -g -I$(INCLUDES)

INCLUDES = includes/

SRC_DIR = src/
SRC_FILES = ps_main.c\
			ps_parsing.c\
			ps_utils.c\
			ps_free.c\
			ps_inits.c\
			ps_overseer.c\
			routine/ps_routine_main.c\
			routine/ps_routine_utils.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR = obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(patsubst %, $(OBJ_DIR)%, $(OBJ_FILES))

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@cc $(FLAGS) $< -c -o $@

$(NAME): $(OBJ)
	@cc -o $(NAME) $(OBJ)
	@echo successfully compiled

clean:
	@rm -rf $(OBJ_DIR)
	@echo Cleaned

silent_clean:
	@rm -rf $(OBJ_DIR)

fclean: silent_clean
	@rm -f $(NAME)
	@echo Fully cleaned

all: $(NAME)

re: fclean all