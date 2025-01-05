CFLAGS = -Wall -Wextra -Werror
CC = cc
PRINTF_DIR = includes/printf
NAME = libminitalk

all: $(NAME)

$(NAME): mandatory bonus

mandatory:
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) server.c -L$(PRINTF_DIR) -lftprintf -o server
	$(CC) $(CFLAGS) client.c -L$(PRINTF_DIR) -lftprintf -o client

bonus:
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) server_bonus.c -L$(PRINTF_DIR) -lftprintf -o server_bonus
	$(CC) $(CFLAGS) client_bonus.c -L$(PRINTF_DIR) -lftprintf -o client_bonus

clean:
	make clean -C $(PRINTF_DIR)
	rm -f server client server_bonus client_bonus

fclean: clean
	make fclean -C $(PRINTF_DIR)
	rm -f server client client_bonus server_bonus

re: fclean all

.PHONY: all mandatory bonus clean fclean re