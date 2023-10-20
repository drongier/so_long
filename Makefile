NAME = so_long

INCLUDES = -I/usr/include -Imlx
 
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)