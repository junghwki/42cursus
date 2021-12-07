#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default constructor called" << std::endl;
	this->_type = "Animal";
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(Animal& animal)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = animal;
}

Animal& Animal::operator=(const Animal& animal)
{
	std::cout << "Animal Assignation operator called" << std::endl;
	this->_type = animal.getType();
	return (*this);
}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout<< "Animal" << std::endl;
}

void Animal::setType(std::string type)
{
	this->_type = type;
}