#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

// class FragTrap : public ClapTrap
class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	~FragTrap();
	FragTrap(const FragTrap& fragtrap);
	FragTrap& operator=(const FragTrap& fragtrap);
	FragTrap(std::string name);
	void attack(std::string const& target);
	void highFivesGuys(void);
};

#endif
