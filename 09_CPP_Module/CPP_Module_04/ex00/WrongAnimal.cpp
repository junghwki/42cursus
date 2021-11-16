#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& wronganimal)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = wronganimal;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wronganimal)
{
	std::cout << "WrongAnimal Assignation operator called" << std::endl;
	this->_type = wronganimal.getType();
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void WrongAnimal::makeSound() const
{
	std::cout<< "WrongAnimal" << std::endl;
}