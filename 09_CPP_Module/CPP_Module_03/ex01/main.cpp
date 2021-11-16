#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a("junghwki");
	//ScavTrap b("juyang");
	ClapTrap b("juyang");

	a.attack("juyang");
	a.takeDemage(10);
	b.takeDemage(10);
	a.beRepaired(10);
	a.guardGate();
	return (0);
}