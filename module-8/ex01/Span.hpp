#include <vector>
#include <cstdlib>
#include <iostream>

//#define HEAP_LIMIT 343
#define HEAP_LIMIT 34359738

class Span
{
	private:
		unsigned long _capacity;
		unsigned int _size;
		int* _data;
		unsigned int _N;
	public:
		Span();
		Span(unsigned long n);
		Span(const Span& other);
		Span& operator=(const Span& other);

		class It: public std::iterator<std::input_iterator_tag, int>
		{
			private:
				int* _p;

			public:
				It();
				It(int* x);
				It(const It& it);
				It& operator++();
				It operator++(int);
				bool operator==(const It& other) const;
				bool operator!=(const It& other) const;
				int& operator*();
		};

		void addNumber(int n);
		void addNumbers(int *list, int start, int end);
		int shortestSpan();
		int longestSpan();

		It begin(void);
		It end(void);

		~Span();
};
