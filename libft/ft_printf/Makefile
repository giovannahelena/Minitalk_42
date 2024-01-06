NAME = libftprintf.a

SOURCES = ft_printf.c ft_putnbr.c ft_putunsig.c ft_putchar.c ft_putstr.c ft_puthex.c ft_putptr.c

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(SOURCES:.c=.o)

CC = cc

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	@$(CC) -c $(SOURCES) $(FLAGS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
