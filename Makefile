CFLAGS = -Wall -Wextra -Werror
CC = gcc
PRINTF_DIR = includes/printf

all:
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) server.c -L$(PRINTF_DIR) -lftprintf -o server
	$(CC) $(CFLAGS) client.c -L$(PRINTF_DIR) -lftprintf -o client
	$(CC) $(CFLAGS) server_bonus.c -L$(PRINTF_DIR) -lftprintf -o server_bn
	$(CC) $(CFLAGS) client_bonus.c -L$(PRINTF_DIR) -lftprintf -o client_bn

clean:
	make clean -C $(PRINTF_DIR)
	rm -f server client server_bn client_bn

fclean:clean
	make fclean -C $(PRINTF_DIR)
	rm -f server client client_bn server_bn

re: fclean all	