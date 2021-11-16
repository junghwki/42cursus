#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongcat)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = wrongcat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat)
{
	std::cout << "WrongCat Assignation operator called" << std::endl;
	this->_type = wrongcat.getType();
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Meow" << std::endl;
}
