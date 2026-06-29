CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = diamondTrap

SOURCES = DiamondTrap.cpp FragTrap.cpp ScavTrap.cpp ClapTrap.cpp main.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = DiamondTrap.hpp FragTrap.hpp ScavTrap.hpp ClapTrap.hpp

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
