CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = phonebook

SOURCES = Contact.cpp Phonebook.cpp utils.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Contact.hpp Phonebook.hpp

# Rules
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
