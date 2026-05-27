CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = zombieHorde

SOURCES = main.cpp Zombie.cpp zombieHorde.cpp ../libfp/libfp.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Zombie.hpp ../libfp/libfp.hpp

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
