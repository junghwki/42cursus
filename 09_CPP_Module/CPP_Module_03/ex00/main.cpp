#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("junghwki");
	ClapTrap b;

	b.attack("juyang");
	b.takeDemage(0);
	b.beRepaired(10);
	a.attack("juyang");
	a.takeDemage(0);
	a.beRepaired(10);
	return (0);
}