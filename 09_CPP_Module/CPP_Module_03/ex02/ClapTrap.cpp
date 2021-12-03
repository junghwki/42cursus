#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitPoint(10), _energyPoint(10), _attackDemage(0)
{
	std::cout << "[ClapTrap] Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& claptrap)
{
	std::cout << "[ClapTrap] Copy constructor called" << std::endl;
	*this = claptrap;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDemage(0)
{
	std::cout << "[ClapTrap] Name constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap)
{
	std::cout << "[ClapTrap] Assignation operator called" << std::endl;
	if (this == &claptrap)
		return (*this);
	this->_name = claptrap._name;
	this->_hitPoint = claptrap._hitPoint;
	this->_energyPoint = claptrap._energyPoint;
	this->_attackDemage = claptrap._attackDemage;
	return (*this);
}

void ClapTrap::attack(std::string const& target)
{
	std::cout << "[ClapTrap] <" << this->_name << "> attacks <" << target << ">, causing <" << this->_attackDemage << "> points of Demage!" << std::endl;
}

void ClapTrap::takeDemage(unsigned int amount)
{
	std::cout << "[ClapTrap] <" << this->_name << "> take <" << amount << "> points of Demage! ";
	this->_energyPoint -= amount;
	std::cout << "Current Energy Point <" << this->_energyPoint << ">" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "[ClapTrap] <" << this->_name << "> repaired <" << amount << "> points!" << std::endl;
	this->_energyPoint += amount;
}