#include "Zombie.hpp"

void Zombie::set_name(std::string name)
{
	this->_name = name;
}

std::string Zombie::get_name()
{
	return(this->_name);
}

void Zombie::announce(void)
{
	std::cout << '<' << this->_name << "> " << "BraiiiiiiinnnzzzZ..." << std::endl;
}