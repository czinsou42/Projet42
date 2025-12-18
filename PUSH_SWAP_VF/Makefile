# Nom de l'exécutable
NAME = push_swap

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Répertoires
LIBFT_DIR = Libft1
LIBFT = $(LIBFT_DIR)/libft.a

# Fichiers sources du projet
SRC = main.c parcing.c check.c push.c swap.c rotate.c reverse_rotate.c \
      sort.c sort_minimal.c utils.c utils2.c ft_lstsize.c

OBJ = $(SRC:.c=.o)

# Règles
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
