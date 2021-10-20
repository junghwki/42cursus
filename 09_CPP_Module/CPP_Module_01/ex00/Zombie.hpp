#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	private:
	std::string name;

	public:
	std::string get_name();
	void announce(void);
	void set_name(std::string name);
};

#endif