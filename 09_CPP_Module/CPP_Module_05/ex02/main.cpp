// #include "Bureaucrat.hpp"
// #include "Form.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "ShrubberyCreationForm.hpp"

// int main()
// {
//     try
//     {
//         Bureaucrat b1("jimkwon", 10);
//         // ! 범위는 1 ~ 150
//         Form* f1 = new ShrubberyCreationForm("wrong form");
//         // Form f2("jimkwon's form", 150, 150);
//         f1->beSigned(b1);
//         // f2.beSigned(b1);
//         std::cout << "---------print Form-----------" << std::endl;
//         // std::cout << f1 << std::endl;
//         // std::cout << f2 << std::endl;
// 		// b1.signForm(f1);
// 		// b1.signForm(f2);
// 		f1->execute(b1);
//     }
//     catch (std::exception & e)
//     {
//         std::cerr << e.what() << std::endl;
//     }

// }

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
        std::cout << "-------_Action_-------------\n";
		ShrubberyCreationForm sForm("sForm");
        sForm.Action();

		RobotomyRequestForm rForm("rForm");
		rForm.Action();

		PresidentialPardonForm pForm("pForm");
		pForm.Action();

		Bureaucrat b("b", 50);

        std::cout << "-------sign and excute-------------\n";
		sForm.beSigned(b);
		b.signForm(sForm);
		sForm.execute(b);
        std::cout << "-------print sForm information-------------\n";
		std::cout << sForm << '\n';
		pForm.beSigned(b);
		b.executeForm(pForm);
        std::cout << "-------rForm is not signed-------------\n";
        // ? pForm.beSigned(b);
		rForm.execute(b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}