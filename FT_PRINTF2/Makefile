NAME = libftprintf.a

CC = cc 
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c ft_utils.c ft_putptr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm  -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re