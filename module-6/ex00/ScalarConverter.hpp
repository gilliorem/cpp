#include <string>

enum TYPE
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	INVALID
};

class ScalarConverter
{
	public:
		static void convert(const std::string& literal);
};
