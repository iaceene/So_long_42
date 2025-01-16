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

SRC_BONUS =	./bonus/memory/memory_tracker_bonus.c \
		./bonus/src/main_bonus.c \
		./bonus/src/get_next_line/get_next_line_utils_bonus.c \
		./bonus/src/get_next_line/get_next_line_bonus.c \
		./bonus/src/parse/ft_splite_bonus.c \
		./bonus/src/parse/parsing_bonus.c \
		./bonus/src/parse/parsing_utiles_bonus.c \
		./bonus/src/parse/ft_check_path_bonus.c \
		./bonus/src/graphic/start_game_bonus.c \
		./bonus/src/graphic/print_moves_bonus.c \
		./bonus/src/graphic/movement_bonus.c \
		./bonus/src/graphic/key_handel_bonus.c \
		./bonus/src/graphic/end_game_bonus.c \
		./bonus/src/graphic/render_bonus.c \
		./bonus/src/graphic/render_utiles_bonus.c \
		./bonus/src/graphic/enemy/ft_enemy_ia_bonus.c \
		./bonus/src/graphic/enemy/enemy_moves_bonus.c \
		./bonus/src/graphic/enemy/ft_map_rebuild_bonus.c \
		./bonus/src/graphic/ft_itoa_bonus.c \
		./bonus/src/graphic/display_moves_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
MLX_LIB = ./mlx_linux/libmlx_Linux.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) $(MLX_LIB) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) $(CFLAGS) $(LDFLAGS) $(MLX_LIB) -o $(NAME_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
