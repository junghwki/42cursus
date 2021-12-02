#include "Intern.hpp"

Intern::Intern()
{
	_makeFormPtr[0] = &PresidentialPardonForm::makePForm;
	_makeFormPtr[1] = &RobotomyRequestForm::makeRForm;
	_makeFormPtr[2] = &ShrubberyCreationForm::makeSForm;
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
	Form* ret;
	std::string name_array[3];
	int	idx;

	idx = 0;
	name_array[0] = "PresidentialPardonForm";
	name_array[1] = "RobotomyRequestForm";
	name_array[2] = "ShrubberyCreationForm";
	while (idx < 3)
	{
		if (name_array[idx] == name)
		{
			ret = this->_makeFormPtr[idx](target);
			std::cout << "Intern creates " << name << std::endl;
			return (ret);
		}
		idx++;
	}
	return (ret);
}