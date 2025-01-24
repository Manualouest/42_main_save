NAME = Render

CC = c++

SOURCES = $(shell find src -name '*.cpp')

LIB = raylib/src/libraylib.a
# LIBINCLUDE = raylib/

OBJECTS = $(SOURCES:.cpp=.o)

INCLUDES = -Iincludes -Iincludes/classes -Iraylib/src

all: $(NAME)

raylib:
	@if ls | grep -q "raylib"; then \
		clear; \
		echo "\033[32;47;1m** raylib already exist **\033[1;m"; \
	else \
		git clone https://github.com/raysan5/raylib.git; \
		cd raylib/src/; \
		make PLATFORM=PLATFORM_DESKTOP; \
	fi


$(NAME): raylib $(OBJECTS)
	$(CC) $(OBJECTS) $(LIB) -o $(NAME) -lm $(INCLUDES) -g
	make -C . clean

%.o: %.cpp
	$(CC) -c $< -o $@ $(INCLUDES) -g

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

libclean:
	rm -rf raylib

re: fclean all