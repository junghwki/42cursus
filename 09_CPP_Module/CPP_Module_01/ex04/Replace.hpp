#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>

class Replace {
private:
	std::string _filename;
	std::string _before;
	std::string _after;
	
public:
	Replace(std::string filename, std::string before, std::string after);
	std::string GetFileName();
	std::string GetBefore();
	std::string GetAfter();
};

#endif