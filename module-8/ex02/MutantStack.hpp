#include <stack>
#include <iostream>
#include <iterator>

/* class Stack
 * {
 * 	private:
 * 		<T> value_type : (int|char|string|size_t....) stack::value_type
 * 		<T> container  : (the container of the type) stack::container_type | stack::c
 * 		size_type: size_t size;
 * 		
 * }
*/

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		
		typename std::stack<T>::container_type::iterator iterator;
		typename std::stack<T>::container_type::const_iterator const_iterator;
		
		MutantStack() {}
		MutantStack(const MutantStack& other): iterator(other.iterator), const_iterator(other.const_iterator)
		{  }
		MutantStack& operator=(const MutantStack& other)
		{
			if (other == this)
				return *this;
			this->iterator = other.iterator;
			this->const_iterator = other.const_iterator;
			return *this;
		}
		~MutantStack() {}

		typename std::stack<T>::container_type::iterator begin()
		{
			return this->c.begin();
		}
		typename std::stack<T>::container_type::iterator end()
		{
			return this->c.end();
		}
		typename std::stack<T>::container_type::const_iterator begin() const
		{
			return this->c.begin();
		}
		typename std::stack<T>::container_type::const_iterator end() const
		{
			return this->c.end();
		}
};
