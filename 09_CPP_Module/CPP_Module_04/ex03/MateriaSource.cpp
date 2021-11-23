#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
}

MateriaSource::~MateriaSource()
{
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materia)
{
}

void MateriaSource::learnMateria(AMateria* amateria)
{
	int idx;

	idx = 0;
	while (idx < 4)
	{
		if (!this->_amateria[idx])
		{
			this->_amateria[idx] = amateria;
			break ;
		}
		idx++;
	}
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	int idx;

	idx = 0;
	while (idx < 4)
	{
		if (this->_amateria[idx]->getType() == type)
			return (this->_amateria[idx]->clone());
	}
	return (0);
}