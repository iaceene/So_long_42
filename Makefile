SRC =	./mandatory/memory/memory_tracker.c \
		./mandatory/src/main.c \
		./mandatory/src/get_next_line/get_next_line_utils.c \
		./mandatory/src/get_next_line/get_next_line.c \
		./mandatory/src/parse/ft_splite.c \
		./mandatory/src/parse/parsing.c \
		./mandatory/src/parse/parsing_utiles.c \
		./mandatory/src/parse/ft_check_path.c \
		./mandatory/src/graphic/start_game.c \
		./mandatory/src/graphic/print_moves.c \
		./mandatory/src/graphic/movement.c \
		./mandatory/src/graphic/key_handel.c \
		./mandatory/src/graphic/end_game.c \
		./mandatory/src/graphic/render.c \
		./mandatory/src/graphic/render_utiles.c



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
	$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) $(MLX_LIB) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
