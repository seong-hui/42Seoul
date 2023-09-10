NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

SRCS :=
SRCS += push_swap.c
SRCS += deque_info1.c
SRCS += deque_info2.c
SRCS += operator1.c
SRCS += operator2.c
SRCS += operator3.c
SRCS += utils.c
SRCS += utils2.c
SRCS += utils3.c
SRCS += utils_for_sort.c
SRCS += utils_for_sort2.c
SRCS += first_step.c
SRCS += check_num.c
SRCS += deque_sort.c
SRCS += cal_min_count.c
SRCS += move_atob.c
SRCS += move_btoa.c
SRCS += free_utils.c

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