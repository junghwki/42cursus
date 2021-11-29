#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& arg)
{
	*this = arg;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern& arg)
{
	(void)arg;
	return (*this);
}

Form* Intern::makeForm(std::string name, std::string target)
{
	std::cout << "Intern creates " << name << std::endl;
}
