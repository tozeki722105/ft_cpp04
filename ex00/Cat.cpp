#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other.type)
{
	std::cout << "Cat Copy Constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat Copy Operator: " << type << std::endl;
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
