NAME = account

FLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = Account.cpp\
		tests.cpp

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