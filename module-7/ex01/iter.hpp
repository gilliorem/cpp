#pragma once
#include <iostream>

template <typename T>
void print(T element)
{
	std::cout << element << std::endl;
}

template <typename T>
void increment(T &element)
{
	element += 1;
}

template <typename T>
void iter(T *array, const size_t size, void(*fun)(T &element))
{
	for (size_t i = 0; i < size; ++i)
		fun(array[i]);
}

