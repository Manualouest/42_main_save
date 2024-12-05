NAME ?= fixed

SRC ?= main.cpp\
		Fixed.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Werror -Wextra -std=c++98

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