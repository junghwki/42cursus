#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>

class Karen {
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	std::string _level[4];
	void (Karen::*_levelPtr[4])(void);

public:
	Karen();
	~Karen();
	void complain(std::string level);
};

#endif