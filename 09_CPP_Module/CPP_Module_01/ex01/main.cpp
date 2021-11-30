#include "Zombie.hpp"

int main (void)
{
	Zombie* ret;

	ret = zombieHorde(10, "sehan");
	delete [] ret;
	return (0);
}