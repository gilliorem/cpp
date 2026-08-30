#pragma once
template <typename T>
void swap(T& a, T& b)
{
	T tmp = b;
	b = a;
	a = tmp;
}

template <typename T>
const T& min(const T& a, const T& b)
{
	if (b <= a)
		return b;
	return a;
}

template <typename T>
const T& max(const T& a, const T& b)
{
	if (b >= a)
		return b;
	return a;
}

