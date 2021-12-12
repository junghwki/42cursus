// #include <iostream>

// struct Data
// {
// 	int i;
// };

// Data* deserialize(uintptr_t raw)
// {

// }

// uintptr_t serialize(Data* ptr)
// {
// 	Data i;

// 	i.i = ptr->i;
// }


#include "Data.hpp"

int main()
{
	t_Data data = {1, 2, 3};

	uintptr_t ptr = serialize(&data);
	t_Data2 *data_ptr = deserialize(ptr);

	std::cout << "----------data origin------------" << std::endl;
	std::cout << "integer1 : " << data.integer << std::endl;
	std::cout << "integer2 : " << data.integer2 << std::endl;
	std::cout << "integer3 : " << data.integer3 << std::endl;
	std::cout << "-------after selialize and deserialize---------" << std::endl;
	std::cout << "integer1 : " << data_ptr->a << std::endl;
	std::cout << "integer2 : " << data_ptr->b << std::endl;
	std::cout << "integer3 : " << data_ptr->c << std::endl;
}