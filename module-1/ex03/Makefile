CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = killzone

SOURCES = main.cpp Weapon.cpp Human.cpp HumanA.cpp HumanB.cpp ../libfp/libfp.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Weapon.hpp Human.hpp HumanA.hpp HumanB.hpp ../libfp/libfp.hpp

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
