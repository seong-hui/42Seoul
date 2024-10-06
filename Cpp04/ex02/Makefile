NAME = Animal
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS :=
SRCS += AAnimal.cpp
SRCS += main.cpp
SRCS += Cat.cpp
SRCS += Dog.cpp
SRCS += WrongAnimal.cpp
SRCS += Brain.cpp

HDRS :=
HDRS += AAnimal.hpp
HDRS += Cat.hpp
HDRS += Dog.hpp
HDRS += WrongAnimal.hpp
HDRS += Brain.hpp

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