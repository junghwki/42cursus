#include "Zombie.hpp"
#include <stdlib.h>

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* ret;
	int idx;

	idx = 0;
	ret = new Zombie[N];
	while (idx < N)
	{
		ret[idx].set_name(name);
		ret[idx].announce();
		idx++;
	}
	return (ret);
}