#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs.type)
{
	std::cout << "Dog copy Constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
