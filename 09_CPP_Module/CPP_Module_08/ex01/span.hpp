#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <vector>

// template<typename T>
class Span
{
public:
	Span(unsigned int N);
	Span(const Span& arg);
	~Span();
	Span& operator=(const Span& arg);
	void addNumber(unsigned int N);
	void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
	class AlreadyExist : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("already exist");
		};
	};

	class FullContainer : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("container is full");
		};
	};

	class NoSpan : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("cannot find span");
		};
	};
	int shortestSpan();
	int longestSpan();
	void showElements();

private:
	Span();
	std::vector<int> _container;
	unsigned int _N;
};

#endif