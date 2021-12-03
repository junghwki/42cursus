#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "[ScavTrap] Default constructor called" << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDemage = 20;
	this->_name = "ScavTrap";
}

ScavTrap::ScavTrap(ScavTrap& scavtrap) : ClapTrap()
{
	std::cout << "[ScavTrap] Copy constructor called" << std::endl;
	*this = scavtrap;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "[ScavTrap] Name constructor called" << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDemage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavtrap)
{
	ClapTrap::operator=(scavtrap);
	std::cout << "[ScavTrap] Assignation operator called" << std::endl;
	return (*this);
}

void ScavTrap::attack(std::string const& target)
{
	std::cout << "[ScavTrap] <" << this->_name << "> attacks <" << target << ">, causing <" << this->_attackDemage << "> points of Demage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] have enterred in Gate keeper mode." << std::endl;
}