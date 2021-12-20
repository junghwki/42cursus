#include "span.hpp"

int	main(void)
{
	Span a(10);
	Span b(10);
	std::vector<int> vec;
	std::vector<int> vec2;
	Span c(10000);

	int idx = 0;

	while (idx < 9)
	{
		a.addNumber(idx);
		idx++;
	}
	try
	{
		a.addNumber(8);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		a.addNumber(9);
		a.addNumber(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	idx = 0;
	while (idx < 10)
	{
		vec.push_back(idx);
		idx++;
	}
	b.addNumber(vec.begin(), vec.end());
	std::cout << a.shortestSpan() << std::endl;
	std::cout << a.longestSpan() << std::endl;
	b.showElements();
	idx = 0;
	while (idx < 10000)
	{
		c.addNumber(idx * 10);
		idx++;
	}
	try
	{
		c.addNumber(vec.begin(), vec.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << c.shortestSpan() << std::endl;
	std::cout << c.longestSpan() << std::endl;
	return (0);
}