#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &dog)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Dog Assignation operator called" << std::endl;
	this->_type = dog.getType();
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
