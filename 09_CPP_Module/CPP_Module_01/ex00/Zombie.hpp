#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
private:
	std::string _name;

public:
	~Zombie();
	void announce(void);
	std::string get_name();
	void set_name(std::string name);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif