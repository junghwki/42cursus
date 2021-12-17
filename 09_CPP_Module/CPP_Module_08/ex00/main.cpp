#include "easyfind.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
	std::vector<int> v_int;
	std::list<int> l_int;
	std::list<int> wrong_int;

	const std::vector<int> v_int_const(3, 42);
	const std::list<int> l_int_const(3, 42);

	std::vector<int>::iterator v_iter;
	std::list<int>::iterator l_iter;

	std::vector<int>::const_iterator v_iter_const;
	std::list<int>::const_iterator l_iter_const;

	for (int i = 0; i < 42; i++)
	{
		v_int.push_back(i + 1);
		l_int.push_back(i + 1);
	}

	try
	{
		v_iter = easyfind(v_int, 42);
		v_iter_const = easyfind(v_int_const, 42);
		l_iter = easyfind(l_int, 42);
		l_iter_const = easyfind(l_int_const, 49);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << *v_iter << std::endl;
	std::cout << *v_iter_const << std::endl;
	std::cout << *l_iter << std::endl;
}