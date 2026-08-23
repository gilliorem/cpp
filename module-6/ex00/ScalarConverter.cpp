#include <cctype>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <climits>
#include <cmath>

#include "ScalarConverter.hpp"

bool isChar(const std::string& literal)
{
	if (literal.length() == 1 && std::isprint(literal[0]) && (!std::isdigit(literal[0])))
		return true;
	return false;
}

bool isInt(const std::string& literal)
{
	std::string::const_iterator it = literal.begin();
	while (it != literal.end())
	{
		if (!std::isdigit(*it))
			return false;
		++it;
	}
	return true;
}

bool isFloat(const std::string& literal)
{
	int pointCount = 0;
	int fCount = 0;
	int signCount = 0;

	std::string::const_iterator it = literal.begin();

	int litLen = literal.length();

	if (literal[litLen] != 'f')
		return false;
	

	while (it != literal.end())
	{
		if (*it == '-' || *it == '+')
		{
			signCount++;
			if (signCount > 1)
				return false;
			++it;
		}
		if (!std::isdigit(*it))
		{
			if (*it == '.')
			{
				pointCount++;
				if (pointCount > 1)
					return false;
			}
			else if (*it == 'f')
			{
				fCount++;
				if (fCount > 1)
					return false;
			}
			else
				return false;
		}
		++it;
	}

	if (pointCount != 1 || fCount != 1)
		return false;
	
	return true;
}

bool isDouble(const std::string& literal)
{
	std::istringstream iss(literal);
	double d;
	iss >> d;
	return iss.eof() && !iss.fail();
}

bool isPseudo(const std::string& literal)
{
    return (literal == "-inff" || literal == "+inff" || literal == "nanf"
            || literal == "-inf" || literal == "+inf" || literal == "nan");
}

void printFloat(float f)
{
	std::cout << std::setprecision(7);
	std::cout << "float: ";
	std::cout << f;
	if (f == std::floor(f))
		std::cout << ".0";
	std::cout << "f\n";
}

void printDouble(double d)
{
	std::cout << std::setprecision(15);
	std::cout << "double: ";
	std::cout << d;
	if (d == std::floor(d))
		std::cout << ".0";
	std::cout << std::endl;
}

TYPE identifyTypeLiteral(const std::string& literal)
{
	if (isChar(literal))
		return CHAR;
	if (isInt(literal))
		return INT;
	if (isFloat(literal))
		return FLOAT;
	if (isDouble(literal))
		return DOUBLE;
	if (isPseudo(literal))
		return PSEUDO;

	return INVALID;
}

void printPseudo(const std::string& literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (literal == "-inff" || literal == "-inf")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (literal == "+inff" || literal == "+inf")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "nanf" || literal == "nan")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }

}

void printChar(double n)
{
	if (n < static_cast<double>(INT_MIN) || n > static_cast<double>(INT_MAX))
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	if (n >= 40 && n <= 176)
	{
		std::cout << "char: '" << static_cast<char>(n)  << "'" << std::endl;
		return;
	}
	std::cout << "char: non-printable\n";
}

void printInt(double n)
{
	if (n < static_cast<double>(INT_MIN) || n > static_cast<double>(INT_MAX))
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	std::cout << "int: " << static_cast<int>(n) << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	TYPE type;
	type = identifyTypeLiteral(literal);
	double db = static_cast<double>(strtod(literal.c_str(), NULL));
	switch (type)
	{
		case PSEUDO:
		{
			printPseudo(literal);
			break;
		}
		case CHAR:
		{
			db = static_cast<double>(literal[0]);
			printChar(db);
			printInt(db);
			printFloat(static_cast<float>(db));
			printDouble(db);

			break;
		}
		case INT:
		{
			char c = static_cast<char>(db);
			printChar(c);
			printInt(db);
			printFloat(static_cast<float>(db));
			printDouble(db);

			break;
		}
		case FLOAT:
		{
			printChar(db);
			printInt(static_cast<int>(db));
			printFloat(static_cast<float>(db));
			printDouble(db);

			break;
		}
		case DOUBLE:
		{
			printChar(db);
			printInt(db);
			printFloat(db);
			printDouble(db);

			break;
		}
		default:
		{
			std::cout << "Error: Literal doesn't match any recorded type!\n";
		}
	}
}
