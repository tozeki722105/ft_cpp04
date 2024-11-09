#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other.type)
{
	std::cout << "Dog Copy Constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog Copy Operator: " << type << std::endl;
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
