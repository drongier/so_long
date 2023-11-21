NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -lX11 -lXext

SRC = so_long.c map.c check.c init_map.c draw_map.c handle_key.c exit_free.c
LIBRARY = libraries/libft/*.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBRARY) $(OBJ) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
