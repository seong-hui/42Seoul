NAME = philo
CC= cc
CFLAGS = 
SRCS :=
SRCS += main.c
SRCS += ft_atoi.c
SRCS += philo_utils.c
SRCS += init_free.c
SRCS += thread.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c  $(CFLAGS) $<

$(NAME): $(OBJS)
	$(CC) -fsanitize=thread -o  $@ $^
	@echo "\033[36m" --- 🔹 Compile Complete 🔹 ---

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re