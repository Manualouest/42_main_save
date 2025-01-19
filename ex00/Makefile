NAME ?= whatever

SRC ?= main.cpp

FLAGS += -Wall -Werror -Wextra -std=c++98 -I../ex00

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	c++ $(FLAGS) $< -c -o $@

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

all: $(NAME)

re: fclean all