CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wno-deprecated-declarations -std=c++98

NAME = bankster

SOURCES = Account.cpp tests.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Account.hpp

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
