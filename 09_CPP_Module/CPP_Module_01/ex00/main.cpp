#include "Zombie.hpp"

int	main(void)
{
	Zombie* ret;
	ret = newZombie("sehan");//힙
	randomChump("sehan");//스택
	delete ret;

	return (0);
}