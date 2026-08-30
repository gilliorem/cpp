CXX = c++ -g
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = swap

SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = whatever.hpp

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
