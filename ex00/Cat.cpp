#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs.type)
{
	std::cout << "Cat copy Constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
