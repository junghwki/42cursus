#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice Default constructor called" << std::endl;
	this->_type = "ice";
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
}

Ice::Ice(const Ice& copy)
{
	std::cout << "Ice Copy constructor called" << std::endl;
	*this = copy;
}

Ice& Ice::operator=(const Ice& ice)
{
	std::cout << "Ice Assignation operator called" << std::endl;
	this->_type = ice._type;
	return (*this);
}

Ice* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
