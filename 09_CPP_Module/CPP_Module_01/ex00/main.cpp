#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int	main(void)
{
	Zombie* ret;
	ret = newZombie("sehan");
	randomChump("sehan");
	delete ret;

	return (0);
}