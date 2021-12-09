#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat a("juyang", 150);
		Bureaucrat b("juyang", 550);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat d("juyang", 1);
		Bureaucrat c("juyang", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat e("junghwki", 1);
		e.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat f("junghwki", 150);
		f.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrat g("mki", 150);
	std::cout << g << std::endl;
}