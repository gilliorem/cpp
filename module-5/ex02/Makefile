CXX = c++ -g
CXXFLAGS = -Wall -Wextra -Werror -std=c++20

NAME = bureaucrat

SOURCES = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) *target_shrubbery
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
