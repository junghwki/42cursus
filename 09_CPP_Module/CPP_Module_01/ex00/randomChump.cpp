#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie ret;

	ret.set_name(name);
	ret.announce();
}