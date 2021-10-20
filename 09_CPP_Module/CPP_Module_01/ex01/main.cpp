#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main (void)
{
	Zombie* ret;

	ret = zombieHorde(10, "sehan");
	delete [] ret;
	return (0);
}