CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = materia

SOURCES = main.cpp Materia.cpp Character.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Materia.hpp Character.hpp

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
