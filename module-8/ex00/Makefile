CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = easyfind

SOURCES = main.cpp

#All the source files compiles into .o files
OBJECTS = $(SOURCES:.cpp=.o) 
HEADERS = easyfind.hpp

all: $(NAME)

#Name need all .o files
#will turn all these .o files into the main executable
$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

# $< is the source file file.cpp
# $@ is the target file file.o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
