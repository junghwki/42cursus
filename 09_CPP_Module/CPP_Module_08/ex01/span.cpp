#include "span.hpp"

Span::Span()
: _N(0)
{
}

Span::Span(unsigned int N)
: _N(N)
{
}

Span::Span(const Span &arg)
: _container(arg._container), _N(arg._N)
{
}

Span::~Span()
{
}

Span &Span::operator=(const Span &arg)
{
	this->_container = arg._container;
	this->_N = arg._N;
	return (*this);
}

void Span::addNumber(unsigned int N)
{
	if (this->_container.size() < this->_N)
	{
		std::vector<int>::iterator iter = std::find(this->_container.begin(), this->_container.end(), N);
		if (iter == this->_container.end())
		{
			this->_container.push_back(N);
		}
		else
		{
			throw AlreadyExist();
		}
	}
	else
	{
		throw FullContainer();
	}
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	while (start != end)
	{
		if (this->_container.size() < this->_N)
			this->_container.push_back(*start);
		else
			throw FullContainer();
		start++;
	}
}

int Span::shortestSpan()
{
	unsigned int max;
	unsigned int temp;

	max = 4294967295;

	if (this->_container.size() < 2)
	{
		throw NoSpan();
	}
	std::sort(this->_container.begin(), this->_container.end());
	std::vector<int>::iterator iter = this->_container.begin();
	std::vector<int>::iterator next_iter = iter + 1;
	while (next_iter != this->_container.end())
	{
		temp = *next_iter - *iter;
		if (temp < max)
		{
			max = temp;
		}
		iter++;
		next_iter++;
	}
	return (max);
}

int Span::longestSpan()
{
	if (this->_container.size() < 2)
	{
		throw NoSpan();
	}
	std::sort(this->_container.begin(), this->_container.end());
	std::vector<int>::iterator begin_iter = this->_container.begin();
	std::vector<int>::iterator end_iter = this->_container.end() - 1;
	return (*end_iter - *begin_iter);
}


void Span::showElements()
{
	std::vector<int>::iterator iter = this->_container.begin();
	while (iter != this->_container.end())
	{
		std::cout << *iter << ", ";
		iter++;
	}
	std::cout << std::endl;
}