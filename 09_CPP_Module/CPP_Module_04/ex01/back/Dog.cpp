#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->_brain = new Brain;
	this->_type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->_brain;
}

Dog::Dog(const Dog &dog)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->_brain = new Brain;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Dog Assignation operator called" << std::endl;
	*(this->_brain) = *(dog._brain);
	this->_type = dog.getType();
	return (*this);
}

Brain* Dog::getBrain()
{
	return (this->_brain);
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
