#include "Cure.hpp"

Cure::Cure()
{
	// std::cout << "Cure Default constructor called" << std::endl;
	this->_type = "cure";
}

Cure::~Cure()
{
	// std::cout << "Cure Destructor called" << std::endl;
}

Cure::Cure(const Cure& copy)
{
	// std::cout << "Cure Copy constructor called" << std::endl;
	*this = copy;
}

Cure& Cure::operator=(const Cure& cure)
{
	// std::cout << "Cure Assignation operator called" << std::endl;
	this->_type = cure._type;
	return (*this);
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
