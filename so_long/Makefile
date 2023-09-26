# all:
# 	gcc -L./mlx -lmlx -framework OpenGL -framework AppKit main.c
# 	./a.out

NAME = so_long
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L./mlx -lmlx -framework OpenGL -framework Appkit

SRCS :=
SRCS += main.c
SRCS += get_next_line.c
SRCS += checking_map.c
SRCS += moving_player.c
SRCS += utils.c
SRCS += utils2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

$(NAME): $(OBJS)
	$(CC) -fsanitize=address -o $@ $^ $(MLX_FLAGS)
	@echo "\033[36m" --- 🔹 Compile Complete 🔹 ---

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re