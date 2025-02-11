NAME ?= scalarconverter

SRC ?= main.cpp\
		ScalarConverter.cpp

FLAGS += -Werror -Wextra -Wall -std=c++98 -I../ex00

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	c++ $(FLAGS) $< -c -o $@

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
