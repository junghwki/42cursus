#include "Zombie.hpp"

void Zombie::set_name(std::string name)
{
	this->name = name;
}

std::string Zombie::get_name()
{
	return(this->name);
}

void Zombie::announce(void)
{
	std::cout << '<' << this->name << "> " << "BraiiiiiiinnnzzzZ..." << std::endl;
}