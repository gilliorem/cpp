CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
AUDIOFLAGS = -lpthread -lm

NAME = bureaucrat

SOURCES = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp miniaudio.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp miniaudio.h

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX)  $(CXXFLAGS) $(AUDIOFLAGS) $(OBJECTS) -o $(NAME)
%.o: %.cpp $(HEADERS)
	$(CXX) $(AUDIOFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) *target_shrubbery
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
