#include <iostream>

int	main(void)
{
	std::string str;
	std::string* stringPTR;
	std::string& stringREF = str;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	std::cout << &str << std::endl;
	std::cout << &stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return (0);
}