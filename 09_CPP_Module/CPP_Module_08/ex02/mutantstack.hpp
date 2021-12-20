#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack& arg);
	~MutantStack();
	MutantStack& operator=(const MutantStack& arg);

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator const_begin();
	const_iterator const_end();
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin();
	reverse_iterator rend();
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator const_rbegin() const;
	const_reverse_iterator const_rend() const;
private:
};

#endif
