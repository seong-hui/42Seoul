NAME = FragTrap
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS :=
SRCS += ClapTrap.cpp
SRCS += main.cpp
SRCS += ScavTrap.cpp
SRCS += FragTrap.cpp

HDRS :=
HDRS += ClapTrap.hpp
HDRS += ScavTrap.hpp
HDRS += FragTrap.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp $(HDRS)
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