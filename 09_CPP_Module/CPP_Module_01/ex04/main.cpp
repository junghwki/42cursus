#include <iostream>
#include <fstream>
#include "Replace.hpp"

int	ft_replace(Replace replace)
{
	std::ifstream f_in;
	std::ofstream f_out(replace.GetFileName().append(".replace"));
	std::string desc;
	size_t	position;
	size_t	idx;

	f_in.open(replace.GetFileName());
	if (f_in.is_open())
	{
		while (getline(f_in, desc))
		{
			while (desc.find(replace.GetBefore()) != std::string::npos)
			{
				position = desc.find(replace.GetBefore());
				desc.erase(position, replace.GetBefore().length());
				desc.insert(position, replace.GetAfter());
				idx = position + replace.GetAfter().length();
				f_out << desc.substr(0, idx);
				desc.erase(0, idx);
			}
			if (!desc.empty())
				f_out << desc << std::endl;
		}
		f_in.close();
		f_out.close();
	}
	else
	{
		std::cout << "Arguments Error" << std::endl;
		return (-1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		Replace replace(argv[1], argv[2], argv[3]);
		return (ft_replace(replace));
	}
	else
	{
		std::cout << "Arguments Error" << std::endl;
		return (-1);
	}
	return (0);
}
