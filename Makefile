NAME = fractol
CC = cc
FLAGS = -Wall -Werror -Wextra -Imlx -O2
SRCS = main.c hook.c mandelbrot.c julia.c free_exit.c ft_atof.c color.c util.c
OBJS = $(SRCS:.c=.o)

MLX_OBJS = $(MLX_SRCS:.c=.o)
MLX_DIR = ./mlx
MLX_A = ./mlx/libmlx.a
INCLUDE = -I $(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(OBJS) $(FLAGS) -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework Cocoa -framework CoreFoundation -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	$(RM) $(MLX_A)
	$(RM) $(NAME)

re: fclean all

debug: re
debug: FLAGS = -Wall -Wextra -g -fsanitize=address