NAME = libft.a

SOURCES_MANDATORY = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c\
ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strdup.c ft_toupper.c ft_memcpy.c ft_tolower.c ft_strchr.c ft_strrchr.c\
ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_substr.c ft_calloc.c ft_strjoin.c  ft_putchar_fd.c\
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_striteri.c ft_strmapi.c ft_strtrim.c ft_split.c ft_str_isdigit.c

SOURCES_BONUS = ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c \
ft_lstiter_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c

FLAGS = -c -g -Wall -Wextra -Werror

OBJECTS_MANDATORY = $(SOURCES_MANDATORY:.c=.o)

OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

CC = cc

all: $(NAME)

$(NAME): $(OBJECTS_MANDATORY)
	@ar rcs $(NAME) $(OBJECTS_MANDATORY)

$(OBJECTS_MANDATORY): $(SOURCES_MANDATORY)
	@$(CC) $(SOURCES_MANDATORY) $(FLAGS)

bonus: $(OBJECTS_BONUS)
	@ar rcs $(NAME) $(OBJECTS_BONUS)

clean:
	@rm -f $(OBJECTS_MANDATORY) $(OBJECTS_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all