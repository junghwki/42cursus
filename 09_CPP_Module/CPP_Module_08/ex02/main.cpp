#include "mutantstack.hpp"
#include "mutantstack.cpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "=============test case=============" << std::endl;

	MutantStack<int> int_stack;

	int_stack.push(1);
	int_stack.push(2);
	int_stack.push(3);

	std::cout << "top element : " << int_stack.top() << std::endl;
	int_stack.pop(); // delete 3
	int_stack.pop(); // delete 2

	std::cout << "top element : " << int_stack.top() << std::endl;
	std::cout << "stack size : " << int_stack.size() << std::endl;
	std::cout << "is empty? : " << int_stack.empty() << std::endl;
	int_stack.pop();
	std::cout << "is empty? : " << int_stack.empty() << std::endl;

	int_stack.push(1);
	int_stack.push(2);
	int_stack.push(3);
	int_stack.push(4);
	int_stack.push(5);
	
	MutantStack<int>::iterator iter = int_stack.begin();
	while (iter != int_stack.end())
	{
		std::cout << *iter << " ";
		iter++;
	}
	std::cout << std::endl;

	MutantStack<int>::reverse_iterator riter = int_stack.rbegin();
	while (riter != int_stack.rend())
	{
		std::cout << *riter << " ";
		riter++;
	}
	std::cout << std::endl;

	MutantStack<const int> const_int_stack;
	const_int_stack.push(1);
	const_int_stack.push(2);
	const_int_stack.push(3);

	std::cout << std::endl;
	return 0;
}