#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		// fuck you1
		Bureaucrat a("juyang", 150);
		// fuck you2
		Bureaucrat b("juyang", 550);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		//fuck you3
		Bureaucrat c("juyang", 0);
		//fuck you4
		Bureaucrat d("juyang", 1);
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