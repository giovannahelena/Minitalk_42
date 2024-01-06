NAME_CLNT = client
NAME_SRVR = server

SRC_CLNT = ./src/client.c
SRC_SRVR = ./src/server.c

OBJ_CLNT = $(SRC_CLNT:%.c=%.o)
OBJ_SRVR = $(SRC_SRVR:%.c=%.o)

PNAME_CLNT = -o $(NAME_CLNT)
PNAME_SRVR = -o $(NAME_SRVR)

LIB = ./libft
FTPRINTF = $(LIB)/ft_printf

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

all: libft $(NAME_CLNT) $(NAME_SRVR)

libft:
	@make -sC $(LIB) --no-print-directory
	@make -C $(FTPRINTF) --no-print-directory

$(NAME_CLNT): $(OBJ_CLNT)
	@$(CC) $(SRC_CLNT) $(LIB)/libft.a $(FTPRINTF)/libftprintf.a $(CFLAGS) $(PNAME_CLNT)

$(NAME_SRVR): $(OBJ_SRVR)
	@$(CC) $(SRC_SRVR) $(LIB)/libft.a $(FTPRINTF)/libftprintf.a $(CFLAGS) $(PNAME_SRVR)

start: all
	./server

clean:
	@make clean -C $(LIB) --no-print-directory
	@make clean -C $(FTPRINTF) --no-print-directory
	@rm -f $(OBJ_CLNT) $(OBJ_SRVR)

fclean: clean
	@make fclean -C $(LIB) --no-print-directory
	@make fclean -C $(FTPRINTF) --no-print-directory
	@rm -f $(NAME_CLNT) $(NAME_SRVR)

re: fclean all

%.o: %.c
	@$(CC) $< $(LIB)/libft.a $(FTPRINTF)/libftprintf.a $(CFLAGS) -o $@

.PHONY: all clean fclean re libft start
