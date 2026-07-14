#include <iostream>
#include <string>


class Bureaucrat
{
	private:
		int _grade;
	public:
		Bureaucrat(int grade):_grade(grade)
	{
		if (grade > 150)
		{
			throw GradeTooLowException();
		}
		if (grade < 1)
		{
			throw GradeTooHighException();
		}
		std::cout << "B created. Grade: " << this->_grade << std::endl;
	}
	class GradeTooHighException: public std::exception
	{
		public:
		virtual const char* what() const noexcept
		{
			return "Grade is too high";
		}
	};
	class GradeTooLowException: public std::exception
	{
		public:
		virtual const char* what() const noexcept
		{
			return "Grade is too low";
		}
	};
};




int main()
{
	std::string hi = "hi";
	try
	{
		//int *array = new int[99999999999999];
		//std::cout << hi.at(3) << std::endl;
		Bureaucrat B(0);
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "GradeTooLowException:" << e.what() << std::endl;
		//std::cout << e.what() << "\n";
		//std::cout << "Exception thrown\n";
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "GradeTooHighException: " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

}
