#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("FUck you", 72, 45)
{
	this->_target = "default target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("FUck you", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& arg)
{
	*this = arg;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& arg)
{
	this->_target = arg._target;
	return (*this);
}

void RobotomyRequestForm::Action() const
{
	std::cout << "Drrrrrr...!!!!!\n";
	srand(time(NULL));
	int a = rand() % 2;
	if (a < 1)
		std::cout << this->_target << " has been robotomized successfully 50% of the time\n";
	else
		std::cout << "It’s a failure\n";
}