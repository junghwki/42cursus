#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
void test()
{
	new Cat;
	new Dog;
	// new Animal; //순수 가상함수
}

int main() {

    test();
}