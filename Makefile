NAME = minitalk
SERVER = server.c
SERVER_BONUS = server_bonus.c
SERVER_NAME = server
CLIENT = client.c
CLIENT_BONUS = client_bonus.c
CLIENT_NAME = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):server client
bonus:server_bonus client_bonus
server:
	@$(CC) $(SERVER) $(UTILS) -o $(SERVER_NAME) $(CFLAGS)
server_bonus:
	@$(CC) $(SERVER_BONUS) $(UTILS_BONUS) -o $(SERVER_NAME) $(CFLAGS)
client:
	@$(CC) $(CLIENT) $(UTILS) -o $(CLIENT_NAME) $(CFLAGS)
client_bonus:
	@$(CC) $(CLIENT_BONUS) $(UTILS_BONUS) -o $(CLIENT_NAME) $(CFLAGS)
clean:
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME)
fclean:
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME)
re: clean all

.PHONY:  server client all clean re bonus