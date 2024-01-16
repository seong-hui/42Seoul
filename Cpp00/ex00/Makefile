NAME = megaphone
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS :=
SRCS += MegaPhone.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

$(NAME): $(OBJS)
	$(CXX) -o $@ $^
	@echo "\033[36m" --- 🔹 Compile Complete 🔹 ---

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME) 

re:
	make fclean
	make all

.PHONY: all clean fclean re