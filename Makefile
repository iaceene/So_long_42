SRC =	./mandatory/memory/memory_tracker.c \
		./mandatory/src/main.c \
		./mandatory/src/get_next_line_utils.c \
		./mandatory/src/get_next_line.c \
		./mandatory/src/ft_splite.c




NAME = so_long
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
MLX_LIB = ./mlx_linux/libmlx_Linux.a

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) $(LDFLAGS) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all