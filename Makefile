NAME = fractol
CC = cc
FLAGS = -Wall -Wextra -Imlx -O2
SRCS = main.c hook.c mandelbrot.c julia.c free_exit.c ft_atof.c color.c util.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all