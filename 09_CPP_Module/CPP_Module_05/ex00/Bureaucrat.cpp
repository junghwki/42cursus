#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default name")
{
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat& arg) : _name(arg._name)
{
	*this = arg;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "fuck you" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& arg)
{
	this->_grade = arg._grade;
	return (*this);
}


std::string Bureaucrat::getName()
{
	return (this->_name);
}

int Bureaucrat::getGrade()
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("fuck you");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("fuck you too");
}

std::ostream& operator<<(std::ostream &out, Bureaucrat& value)
{
	out << "<" << value.getName() << ">" << ", bureaucrat grade <" << value.getGrade() << ">." << std::endl;
	return (out);
}