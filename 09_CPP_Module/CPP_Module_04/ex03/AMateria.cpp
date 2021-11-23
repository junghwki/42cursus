#include "AMateria.hpp"

AMateria::AMateria()
{
	// std::cout << "AMateria Default constructor called" << std::endl;
	this->_type = "AMateria";
}

AMateria::~AMateria()
{
	// std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& copy)
{
	// std::cout << "AMateria Copy constructor called" << std::endl;
	*this = copy;
}

AMateria& AMateria::operator=(const AMateria& amateria)
{
	// std::cout << "AMateria Assignation operator called" << std::endl;
	this->_type = amateria._type;
	return (*this);
}

AMateria::AMateria(std::string const& type)
{
	this->_type = type;
}

std::string const& AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* AMateria " << target.getName() << " *" << std::endl;
}