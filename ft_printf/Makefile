CC=cc
CFLAGS=-Wall -Wextra -Werror
AR=ar -rc
SRCS = ft_print_fd.c ft_print_fd2.c ft_printf.c
OBJS=${SRCS:.c=.o}
NAME=libftprintf.a

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
