#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int	main(void)
{
	std::vector<int> a;
	std::vector<int>::iterator iter1;
	std::vector<int>::iterator iter2;
	int idx = 0;
	std::list<int> b;
	std::list<int>::iterator iter3;
	std::list<int>::iterator iter4;
	std::vector<int> c;
	std::vector<int>::iterator iter5;

	while (idx < 10)
	{
		a.push_back(idx);
		b.push_back(idx);
		idx++;
	}
	try
	{
		iter1 = easyfind(a, 9);
		iter2 = easyfind(a, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		iter3 = easyfind(b, 1);
		iter4 = easyfind(b, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		iter5 = easyfind(c, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *iter1 << std::endl;
	std::cout << *iter3 << std::endl;
	return (0);
}
