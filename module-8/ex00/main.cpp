#include <string>
#include <vector>
#include <list>
#include "easyfind.hpp"
#include <exception>

#define MIN -10
#define MAX 15

int main()
{
	std::vector<int> vector;
	std::list<int> list;
	for (int i = 0; i < 5; ++i)
	{
		list.push_back(i);
		vector.push_back(i);
	}
	for (int i = MIN; i < MAX; ++i)
	{
		try
		{
			int res = easyfind(list, i);
			int vectRes = easyfind(vector, i);
			std::cout << "list:" << res << std::endl;
			std::cout << "vector: " << vectRes << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what();
		}
	}
	return 0;
}
