#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->_brain = new Brain;
	this->_type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->_brain;
}

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->_brain = new Brain;
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Cat Assignation operator called" << std::endl;

	*(this->_brain) = *(cat._brain);
	this->_type = cat.getType();
	return (*this);
}

Brain* Cat::getBrain()
{
	return (this->_brain);
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
