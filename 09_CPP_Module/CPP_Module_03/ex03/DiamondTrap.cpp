#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "[DiamondTrap] Default constructor called" << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDemage = 30;
	this->_name = "DiamondTrap";
	ClapTrap::_name = "DiamondTrap_clap_name";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap& diamondtrap)
{
	std::cout << "[DiamondTrap] Copy constructor called" << std::endl;
	*this = diamondtrap;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondtrap)
{
	ClapTrap::_name = diamondtrap.ClapTrap::_name;
	std::cout << "[DiamondTrap] Assignation operator called" << std::endl;
	this->_name = diamondtrap._name;
	this->_hitPoint = diamondtrap._hitPoint;
	this->_energyPoint = diamondtrap._energyPoint;
	this->_attackDemage = diamondtrap._attackDemage;
	return (*this);
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "[DiamondTrap] Name constructor called" << std::endl;
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDemage = 30;
}

void DiamondTrap::attack(std::string const& target)
{
	ScavTrap::attack(target);
	std::cout << "[DiamondTrap] <" << this->_name << "> attacks <" << target << ">, causing <" << this->_attackDemage << "> points of Demage!" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "my name is " << this->_name << " and my ClapTrap name is " << this->ClapTrap::_name << std::endl; 
}