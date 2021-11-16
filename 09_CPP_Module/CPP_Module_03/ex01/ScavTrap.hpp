#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(ScavTrap& scavtrap);
	ScavTrap& operator=(const ScavTrap& scavtrap);
	ScavTrap(std::string name);
	void guardGate();
	void attack(std::string const& target);
};

#endif
