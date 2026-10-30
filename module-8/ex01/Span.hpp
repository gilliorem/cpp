#include <cstdlib>
#include <iterator>

class ContainerSizeException: public std::exception
{
	public:
		virtual const char* what() const throw();
};

class Span
{
	private:
		unsigned int N; // maximum capacity
		unsigned int _size;
		int* _data;
	public:
		Span();
		Span(unsigned int n);
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
		void addNumbers(Span::It begin, Span::It end);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		It begin(void);
		It end(void);

		~Span();
};
