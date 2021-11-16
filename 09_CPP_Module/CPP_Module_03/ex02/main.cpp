#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap junghwki("junghwki");
	ScavTrap juyang("juyang");
	FragTrap sehan("sehan");

	junghwki.attack("juyang");
	juyang.attack("himself");
	sehan.attack("juyang");
	return (0);
}