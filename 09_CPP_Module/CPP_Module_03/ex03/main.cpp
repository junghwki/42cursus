#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap junghwki("junghwki");
	DiamondTrap juyang;
	//ClapTrap junghwki("junghwki");
	//ScavTrap juyang("juyang");
	//FragTrap sehan("sehan");

	//junghwki.attack("juyang");
	//juyang.attack("himself");
	//sehan.attack("juyang");
	junghwki.whoAmI();
	junghwki.attack("juyang");
	juyang.whoAmI();
	return (0);
}