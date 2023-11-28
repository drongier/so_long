NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -lX11 -lXext

SRC = sources/*.c
LIBRARY = libraries/libft/*.c libraries/ft_printf/*.c

OBJ = $(patsubst %.c,%.o,$(wildcard $(SRC)))

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
