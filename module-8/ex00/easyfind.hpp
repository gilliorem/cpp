#include <exception>
#include <algorithm>

class NotFoundException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Value not found";
		}
};

template <typename T>
typename T::iterator easyfind(T &c, int value)
{
	typename T::iterator it;
	it = std::find(c.begin(), c.end(), value);
	if (it == c.end())
		throw NotFoundException();
	return it;
}
