NAME = fractol
CC = cc
FLAGS = -Wall -Wextra -Imlx
SRCS = main.c hook.c mandelbrot.c julia.c free_exit.c ft_atof.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a
INCLUDE = -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(OBJS) -L $(LIBFT_DIR) -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBFT_A)
	rm -f $(NAME)

re: fclean all