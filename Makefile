CFLAGS = -Wall -Wextra -Werror
CC = gcc
PRINTF_DIR = includes/printf

all:
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) server.c -L$(PRINTF_DIR) -lftprintf -o server
	$(CC) $(CFLAGS) client.c -L$(PRINTF_DIR) -lftprintf -o client

clean:
	make clean -C $(PRINTF_DIR)
	rm -f server client

fclean:clean
	make fclean -C $(PRINTF_DIR)
	rm -f server client

re: fclean all	