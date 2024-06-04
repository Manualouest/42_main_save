CLIENT_NAME = client
C_SRC = code_client.c

SERVER_NAME = server
S_SRC = code_server.c

BCLIENT_NAME = client_bonus
BC_SRC = code_client_bonus.c

BSERVER_NAME = server_bonus
BS_SRC = code_server_bonus.c

SRC = utils.c ft_strjoin.c

C_OBJS = $(C_SRC:.c=.o) $(SRC:.c=.o)
S_OBJS = $(S_SRC:.c=.o) $(SRC:.c=.o)

BC_OBJS = $(BC_SRC:.c=.o) $(SRC:.c=.o)
BS_OBJS = $(BS_SRC:.c=.o) $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o:%.c
	clang $(CFLAGS) $< -g -c -o $@

all:$(CLIENT_NAME) $(SERVER_NAME) extra

$(CLIENT_NAME) : $(C_OBJS)
	clang -g $(C_OBJS) -o $(CLIENT_NAME)

$(SERVER_NAME) : $(S_OBJS)
	clang -g $(S_OBJS) -o $(SERVER_NAME)

bonus: $(BCLIENT_NAME) $(BSERVER_NAME) extra

$(BCLIENT_NAME) : $(BC_OBJS)
	clang -g $(BC_OBJS) -o $(BCLIENT_NAME)

$(BSERVER_NAME) : $(BS_OBJS)
	clang -g $(BS_OBJS) -o $(BSERVER_NAME)

extra:
	clear
	@echo "Done :)"

clean:
	rm -f $(C_OBJS)
	rm -f $(S_OBJS)
	rm -f $(BC_OBJS)
	rm -f $(BS_OBJS)
	clear
	@echo "cleaned :)"

fclean: clean
	rm -f $(CLIENT_NAME)
	rm -f $(SERVER_NAME)
	rm -f $(BCLIENT_NAME)
	rm -f $(BSERVER_NAME)
	clear
	@echo "fcleaned :)"

re: fclean all
