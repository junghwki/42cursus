#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(AMateria& copy)
{
}

AMateria::AMateria& operator=(const AMateria& amateria)
{
}

AMateria(std::string const & type)
{
	this->_type = type;
}

std::string const & getType() const; //Returns the materia typ
{
	return (this->_type);
}

virtual void use(ICharacter& target)
{
}
