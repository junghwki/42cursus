#ifndef _DATA_HPP
#define _DATA_HPP
#include <iostream>
#include <string>

typedef struct s_Data
{
	int integer;
	int integer2;
	int integer3;
}	t_Data;

typedef struct s_Data2
{
	int a;
	// unsigned int a;
	int b;
	int c;
}	t_Data2;

uintptr_t serialize(t_Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
	//포인터값와 실제값의 강제 형변환
}
t_Data2* deserialize(uintptr_t raw)
{
	return reinterpret_cast<t_Data2 *>(raw);
}

#endif