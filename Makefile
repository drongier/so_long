NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = so_long.c map.c check.c
LIBRARY = libraries/libft/*.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBRARY) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
