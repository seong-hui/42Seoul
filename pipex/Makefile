NAME = pipex
CFLAGS = -Wall -Wextra -Werror

SRCS :=
SRCS += main.c
SRCS += pipex.c
SRCS += utils.c
SRCS += utils2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

$(NAME): $(OBJS)
	$(CC) -o $@ $^
	@echo "\033[36m" --- 🔹 Compile Complete 🔹 ---

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re