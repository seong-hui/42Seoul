NAME = a.out
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS :=
SRCS += AMateria.cpp
SRCS += main.cpp
SRCS += Character.cpp
SRCS += Cure.cpp
SRCS += Ice.cpp
SRCS += MateriaSource.cpp

HDRS :=
HDRS += AMateria.hpp
HDRS += Character.hpp
HDRS += ICharacter.hpp
HDRS += Cure.hpp
HDRS += Ice.hpp
HDRS += IMateriaSource.hpp
HDRS += MateriaSource.hpp


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