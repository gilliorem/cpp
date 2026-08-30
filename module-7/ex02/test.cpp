#include <iostream>
class Array
{
	private:
		int* element;
		int size;

	public:
		Array(int n)
		{
			this->size = n;
			this->element = new int[this->size]();
		}

		void print_element(int index)
		{
			std::cout << element[index] << std::endl;
		}
		Array& write_element(int index, int new_element)
		{
			this->element[index] = new_element;
			return *this;
		}
		int operator[](int index)
		{
			return element[index];
		}
};

int main()
{
	Array a(3);
	std::cout << a[0] << std::endl;

	a.write_element(0,4);
	std::cout << a[0] << std::endl;
}
