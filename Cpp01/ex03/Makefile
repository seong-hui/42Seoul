NAME = ex03
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS :=
SRCS += main.cpp
SRCS += Weapon.cpp
SRCS += HumanA.cpp
SRCS += HumanB.cpp

HDRS :=
HDRS += Weapon.hpp
HDRS += HumanA.hpp
HDRS += HumanB.hpp

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