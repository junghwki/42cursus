#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << "Zombie Destructor called" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << '<' << this->_name << "> " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->_name = name;
}

std::string Zombie::get_name()
{
	return(this->_name);
}