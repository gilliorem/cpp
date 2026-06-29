CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = bsp

SOURCES = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Fixed.hpp Point.hpp

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
