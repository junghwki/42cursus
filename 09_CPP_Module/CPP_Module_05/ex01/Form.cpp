#include "Form.hpp"

Form::Form() : _name("default name"), _signed(false)
{
}

Form::Form(const Form& arg) : _name(arg._name), _signed(arg._signed)
{
}

Form::~Form()
{
}

Form& Form::operator=(const Form& arg)
{
}

const std::string Form::getName()
{
	return (this->_name);
}

bool Form::getSigned()
{
	return (this->_signed);
}

const int Form::getToSign()
{
	return (this->_toSign);
}

const int Form::getToExecute()
{
	return (this->_toExecute);
}

void beSigned(Bureaucrat& arg)
{
	if (arg.getGrade() < 1)
		throw Form::GradeTooLowException();
	else if (arg.getGrade() > 150)
		throw Form::GradeTooHighException();
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("fuck you");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("fuck you too");
}

std::ostream &operator<<(std::ostream& out,Form& value)
{
	out << "name : " << value.getName() << std::endl;
	out << "signed : " << value.getSigned() << std::endl;
	out << "to signed : " << value.getToSign() << std::endl;
	out << "to execute : " << value.getToExecute() << std::endl;
}