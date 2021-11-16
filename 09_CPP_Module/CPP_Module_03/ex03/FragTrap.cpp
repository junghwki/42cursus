#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDemage = 30;
	this->_name = "FragTrap";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap &fragtrap)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = fragtrap;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Name constructor called" << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDemage = 30;
}

FragTrap &FragTrap::operator=(const FragTrap& fragtrap)
{
	ClapTrap::operator=(fragtrap);
	std::cout << "FragTrap Assignation operator called" << std::endl;
	return (*this);
}

void FragTrap::attack(std::string const &target)
{
	std::cout << "FragTrap <" << this->_name << "> attacks <" << target << ">, causing <" << this->_attackDemage << "> points of Demage!" << std::endl;
}

void highFivesGuys(void)
{
	std::cout << "FragTrap request Positive High Fives" << std::endl;
}