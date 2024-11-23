NAME = Phonebook

FLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = PhoneBook.cpp\
		Contact.cpp\
		main.cpp

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