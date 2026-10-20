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
		void print()
		{
			for (size_t i = 0; i < std::stack<T>::size(); i++)
				std::cout << std::stack<T>::c[i] << " ";
			std::cout << std::endl;
		}

	class It: public std::iterator<std::input_iterator_tag, T>
	{
		private:
			T* _p;
		public:
			It()
			{
				_p = NULL;
			}
			It(T* x): _p(x) {}
	};
};

