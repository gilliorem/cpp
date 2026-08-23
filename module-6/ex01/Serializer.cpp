#include <cstdint>
#include <iostream>
#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t int_ptr;
	int_ptr = reinterpret_cast<uintptr_t>(ptr);
	return int_ptr;
}

Serializer::Data* Serializer::deserialize(uintptr_t raw)
{
	Data* ptr;
	ptr = reinterpret_cast<Data*>(raw);
	return ptr;
}

int main()
{
	Serializer::Data a;
	a.x = 42;
	a.y = 21;

	std::cout << "Values before serializing: {" << a.x << ", " << a.y << "}\n";
	std::cout << "address of data before serializing: " << &a << std::endl;
	uintptr_t int_ptr;
	int_ptr = Serializer::serialize(&a);
	std::cout << int_ptr << std::endl;
	std::cout << "address of data after serialization: " << &a << std::endl;
	std::cout << "Values after serializing: {" << a.x << ", " << a.y << "}\n";

	Serializer::Data* p = Serializer::deserialize(int_ptr);
	std::cout << "address of original value of data pointer: " << &a << std::endl;
	std::cout << "address of data after deserialize:	   " << p << std::endl;
	std::cout << "Values after deserializing: {" << a.x << ", " << a.y << "}\n";

	return 0;
}
