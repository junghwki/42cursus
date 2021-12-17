#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <algorithm>

class CannotFind : public std::exception
{
public:
	const char* what() const throw()
	{
		return ("cannot find argument");
	};
};

class EmptyContainer : public std::exception
{
public:
	const char* what() const throw()
	{
		return ("empty contatiner");
	};
};

template <typename T>
typename T::iterator easyfind(T &container, int whatever)
{
	// std::cout << "default iterator" << std::endl;
	if (container.begin() == container.end())
	{
		throw EmptyContainer();
	}
	typename T::iterator iter = std::find(container.begin(), container.end(), whatever);
	if (iter == container.end())
	{
		throw CannotFind();
	}
	return (iter);
};

template <typename T>
typename T::const_iterator easyfind(const T &container, int whatever)
{
	// std::cout << "const iterator" << std::endl;
	if (container.begin() == container.end())
	{
		throw EmptyContainer();
	}
	typename T::const_iterator iter = std::find(container.begin(), container.end(), whatever);
	if (iter == container.end())
	{
		throw CannotFind();
	}
	return (iter);
};

#endif