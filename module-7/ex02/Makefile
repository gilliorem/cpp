CXX = c++ -g
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = a.out

SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = iter.hpp Array.hpp

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
