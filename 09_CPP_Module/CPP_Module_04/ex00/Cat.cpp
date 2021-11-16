#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Cat Assignation operator called" << std::endl;
	this->_type = cat.getType();
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
