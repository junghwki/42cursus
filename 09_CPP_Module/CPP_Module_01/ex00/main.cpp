#include "Zombie.hpp"

int	main(void)
{
	Zombie* ret;
	ret = newZombie("sehan");//스택
	randomChump("sehan");//힙
	delete ret;

	return (0);
}