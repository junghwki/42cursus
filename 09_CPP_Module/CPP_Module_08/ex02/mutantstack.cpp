#include "mutantstack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& arg)
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& arg)
{
	if (this == &arg)
		return (*this);
	this->c = arg.c;
	return (*this);
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::const_begin()
{
	return (this->c.const_begin());
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::const_end()
{
	return (this->c.const_end());
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::const_rbegin() const
{
	return (this->c.rbegin());
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::const_rend() const
{
	return (this->c.rend());
}
